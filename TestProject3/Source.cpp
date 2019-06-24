//#include <opencv2/opencv.hpp>
//#include <iostream>
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat img = imread("img1.jpg");
//	namedWindow("image", WINDOW_NORMAL);
//	imshow("image", img);
//	waitKey(0);
//	return 0;
//}









#ifdef WIN32
#define ourImread(filename, isColor) cvLoadImage(filename.c_str(), isColor)
#else
#define ourImread(filename, isColor) imread(filename, isColor)
#endif

//
//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//int main(int argc, char** argv)
//{
//	// Read the image file
//	Mat image = imread("lena.png");
//
//	// Check for failure
//	if (image.empty())
//	{
//		cout << "Could not open or find the image" << endl;
//		cin.get(); //wait for any key press
//		return -1;
//	}
//
//	String windowName = "The Guitar"; //Name of the window
//
//	namedWindow(windowName); // Create a window
//
//	imshow(windowName, image); // Show our image inside the created window.
//
//	waitKey(0); // Wait for any keystroke in the window
//
//	destroyWindow(windowName); //destroy the created window
//
//	return 0;
//}










//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include "Tserial.h"
//using namespace cv;
//using namespace std;
///** Function Headers */
//void detectAndDisplay(Mat frame);
///** Global variables */
////-- Обратите внимание: либо скопируйте эти два файла из opencv / data / haarscascades в вашу текущую папку, либо измените эти места
//String face_cascade_name = "haarcascade_frontalface_alt.xml";
//String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
//CascadeClassifier face_cascade;
//CascadeClassifier eyes_cascade;
//string window_name = "Capture - Face detection - Remixed by TechBitar";
//
//// Serial to Arduino global declarations
//int arduino_command;
//Tserial *arduino_com;
//short MSBLSB = 0;
//unsigned char MSB = 0;
//unsigned char LSB = 0;
//// Serial to Arduino global declarations
//
//int main(int argc, char*  argv[])
//{
//	CvCapture* capture;
//	Mat frame;
//
//	// serial to Arduino setup 
//	arduino_com = new Tserial();
//	if (arduino_com != 0)
//	{
//		arduino_com->connect("COM3", 57600, spNONE);
//	}
//	// serial to Arduino setup 
//
//	//Open the default video camera
//	VideoCapture cap(1); 
//
//	// if not success, exit program
//	if (cap.isOpened() == false)
//	{
//		cout << "Cannot open the video camera" << endl;
//		cin.get();  //wait for any key press
//		return -1;
//	}
//
//	double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);  //get the width of frames of the video
//	double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT);  //get the height of frames of the video
//
//	cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;
//
//	string window_name = "My Camera Feed";
//	namedWindow(window_name);  //create a window called "My Camera Feed"
//
//	while (true)
//	{
//		Mat frame;
//		bool bSuccess = cap.read(frame);  // read a new frame from video 
//
//		//Breaking the while loop if the frames cannot be captured
//		if (bSuccess == false)
//		{
//			cout << "Video camera is disconnected" << endl;
//			cin.get();  //Wait for any key press
//			break;
//		}
//
//		//show the frame in the created window
//		imshow(window_name, frame);
//
//		//wait for for 10 ms until any key is pressed. 
//		//If the 'Esc' key is pressed, break the while loop.
//		//If the any other key is pressed, continue the loop 
//		//If any key is not pressed withing 10 ms, continue the loop 
//		if (waitKey(10) == 27)
//		{
//			cout << "Esc key is pressed by user. Stoppig the video" << endl;
//			break;
//		}
//	}
//	// Serial to Arduino - shutdown
//	arduino_com->disconnect();
//	delete arduino_com;
//	arduino_com = 0;
//	// Serial to Arduino - shutdown
//	return 0;
//
//}
////
////void detectAndDisplay(Mat frame)
////{
////
////	std::vector<Rect> faces;
////	Mat frame_gray;
////
////	cvtColor(frame, frame_gray, CV_BGR2GRAY);
////	equalizeHist(frame_gray, frame_gray);
////	//-- Определить лица
////	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
////
////	for (int i = 0; i < faces.size(); i++)
////	{
////		Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
////		ellipse(frame, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 2, 8, 0);
////		//  cout << "X:" << faces[i].x  <<  "  y:" << faces[i].y  << endl;
////
////		 // отправить X, Y фейс центра к последовательному порту
////		 // отправить ось X
////		 // читаем младший байт
////		LSB = faces[i].x & 0xff;
////		// читать следующий значащий байт
////		MSB = (faces[i].x >> 8) & 0xff;
////		arduino_com->sendChar(MSB);
////		arduino_com->sendChar(LSB);
////
////		//Отправить ось Y
////		LSB = faces[i].y & 0xff;
////		MSB = (faces[i].y >> 8) & 0xff;
////		arduino_com->sendChar(MSB);
////		arduino_com->sendChar(LSB);
////		// последовательный порт com
////
////		Mat faceROI = frame_gray(faces[i]);
////		std::vector<Rect> eyes;
////	}
////
////	//-- Покажите, что вы получили
////	imshow(window_name, frame);
////
////}













//
//#include <opencv2/opencv.hpp>
//#include <iostream>
//using namespace cv;
//using namespace std;
//int main(int argc, char* argv[])
//{
//	//Open the default video camera
//	VideoCapture cap(1);
//
//	// if not success, exit program
//	if (cap.isOpened() == false)
//	{
//		cout << "Cannot open the video camera" << endl;
//		cin.get(); //wait for any key press
//		return -1;
//	}
//
//	double dWidth = cap.get(CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
//	double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
//
//	cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;
//
//	string window_name = "My Camera Feed";
//	namedWindow(window_name); //create a window called "My Camera Feed"
//
//	while (true)
//	{
//		Mat frame;
//		bool bSuccess = cap.read(frame); // read a new frame from video 
//
//		//Breaking the while loop if the frames cannot be captured
//		if (bSuccess == false)
//		{
//			cout << "Video camera is disconnected" << endl;
//			cin.get(); //Wait for any key press
//			break;
//		}
//
//		//show the frame in the created window
//		imshow(window_name, frame);
//
//		//wait for for 10 ms until any key is pressed. 
//		//If the 'Esc' key is pressed, break the while loop.
//		//If the any other key is pressed, continue the loop 
//		//If any key is not pressed withing 10 ms, continue the loop 
//		if (waitKey(10) == 27)
//		{
//			cout << "Esc key is pressed by user. Stoppig the video" << endl;
//			break;
//		}
//	}
//
//	return 0;
//
//}












#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/core.hpp"
#include "opencv2/dnn.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/cvconfig.h"
#include <stdlib.h>
#include "opencv2/opencv_modules.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/stitching/warpers.hpp"
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	VideoCapture cap(1); //capture the video from web cam

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}

	namedWindow("Control", WINDOW_AUTOSIZE); //create a window called "Control"

	int iLowH = 0;
	int iHighH = 179;

	int iLowS = 0;
	int iHighS = 255;

	int iLowV = 0;
	int iHighV = 255;

	//Create trackbars in "Control" window
	cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
	cvCreateTrackbar("HighH", "Control", &iHighH, 179);

	cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
	cvCreateTrackbar("HighS", "Control", &iHighS, 255);

	cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
	cvCreateTrackbar("HighV", "Control", &iHighV, 255);

	while (true)
	{
		Mat imgOriginal;

		bool bSuccess = cap.read(imgOriginal); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		Mat imgHSV;

		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

		Mat imgThresholded;

		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

	   //morphological opening (remove small objects from the foreground)



		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//morphological closing (fill small holes in the foreground)
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		imshow("Thresholded Image", imgThresholded); //show the thresholded image



		imshow("Original", imgOriginal); //show the original image

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	return 0;

}