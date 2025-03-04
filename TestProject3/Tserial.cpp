#define STRICT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
#include <conio.h>
#include <windows.h>

#include "Tserial.h"

Tserial::Tserial()
{
	parityMode = spNONE;
	port[0] = 0;
	rate = 0;
	serial_handle = INVALID_HANDLE_VALUE;
}


Tserial::~Tserial()
{
	if (serial_handle != INVALID_HANDLE_VALUE)
		CloseHandle(serial_handle);
	serial_handle = INVALID_HANDLE_VALUE;
}

void Tserial::disconnect(void)
{
	if (serial_handle != INVALID_HANDLE_VALUE)
		CloseHandle(serial_handle);
	serial_handle = INVALID_HANDLE_VALUE;
}
/* -------------------------------------------------------------------- */
/* --------------------------    connect      ------------------------- */
/* -------------------------------------------------------------------- */
int  Tserial::connect(char *port_arg, int rate_arg, serial_parity parity_arg)
{
	int erreur;
	DCB  dcb;
	COMMTIMEOUTS cto = { 0, 0, 0, 0, 0 };

	/* --------------------------------------------- */
	if (serial_handle != INVALID_HANDLE_VALUE)
		CloseHandle(serial_handle);
	serial_handle = INVALID_HANDLE_VALUE;

	erreur = 0;

	if (port_arg != 0)
	{
//		strncpy(port, port_arg, 10);
		rate = rate_arg;
		parityMode = parity_arg;
		memset(&dcb, 0, sizeof(dcb));

		/* -------------------------------------------------------------------- */
		// set DCB to configure the serial port
		dcb.DCBlength = sizeof(dcb);

		/* ---------- Serial Port Config ------- */
		dcb.BaudRate = rate;

		switch (parityMode)
		{
		case spNONE:
			dcb.Parity = NOPARITY;
			dcb.fParity = 0;
			break;
		case spEVEN:
			dcb.Parity = EVENPARITY;
			dcb.fParity = 1;
			break;
		case spODD:
			dcb.Parity = ODDPARITY;
			dcb.fParity = 1;
			break;
		}


		dcb.StopBits = ONESTOPBIT;
		dcb.ByteSize = 8;

		dcb.fOutxCtsFlow = 0;
		dcb.fOutxDsrFlow = 0;
		dcb.fDtrControl = DTR_CONTROL_DISABLE;
		dcb.fDsrSensitivity = 0;
		dcb.fRtsControl = RTS_CONTROL_DISABLE;
		dcb.fOutX = 0;
		dcb.fInX = 0;

		/* ----------------- misc parameters ----- */
		dcb.fErrorChar = 0;
		dcb.fBinary = 1;
		dcb.fNull = 0;
		dcb.fAbortOnError = 0;
		dcb.wReserved = 0;
		dcb.XonLim = 2;
		dcb.XoffLim = 4;
		dcb.XonChar = 0x13;
		dcb.XoffChar = 0x19;
		dcb.EvtChar = 0;

		/* -------------------------------------------------------------------- */
		serial_handle = CreateFile(port, GENERIC_READ | GENERIC_WRITE,
			0, NULL, OPEN_EXISTING, NULL, NULL);
		// opening serial port


		if (serial_handle != INVALID_HANDLE_VALUE)
		{
			if (!SetCommMask(serial_handle, 0))
				erreur = 1;

			// set timeouts
			if (!SetCommTimeouts(serial_handle, &cto))
				erreur = 2;

			// set DCB
			if (!SetCommState(serial_handle, &dcb))
				erreur = 4;
		}
		else
			erreur = 8;
	}
	else
		erreur = 16;


	/* --------------------------------------------- */
	if (erreur != 0)
	{
		CloseHandle(serial_handle);
		serial_handle = INVALID_HANDLE_VALUE;
	}
	return(erreur);
}

void Tserial::sendChar(char data)
{
	sendArray(&data, 1);
}

void Tserial::sendArray(char *buffer, int len)
{
	unsigned long result;

	if (serial_handle != INVALID_HANDLE_VALUE)
		WriteFile(serial_handle, buffer, len, &result, NULL);
}

char Tserial::getChar(void)
{
	char c;
	getArray(&c, 1);
	return(c);
}

int  Tserial::getArray(char *buffer, int len)
{
	unsigned long read_nbr;

	read_nbr = 0;
	if (serial_handle != INVALID_HANDLE_VALUE)
	{
		ReadFile(serial_handle, buffer, len, &read_nbr, NULL);
	}
	return((int)read_nbr);
}

int Tserial::getNbrOfBytes(void)
{
	struct _COMSTAT status;
	int             n;
	unsigned long   etat;

	n = 0;

	if (serial_handle != INVALID_HANDLE_VALUE)
	{
		ClearCommError(serial_handle, &etat, &status);
		n = status.cbInQue;
	}


	return(n);
}
