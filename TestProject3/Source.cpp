#ifdef WIN32
#define ourImread(filename, isColor) cvLoadImage(filename.c_str(), isColor)
#else
#define ourImread(filename, isColor) imread(filename, isColor)
#endif

#define 	CV_FOURCC_DEFAULT   CV_FOURCC('I', 'Y', 'U', 'V')
#define 	CV_FOURCC_MACRO(c1, c2, c3, c4)   (((c1) & 255) + (((c2) & 255) << 8) + (((c3) & 255) << 16) + (((c4) & 255) << 24))
#define 	CV_FOURCC_PROMPT   -1

#include "iostream"
#include "opencv2/cvconfig.h"
#include "opencv2/core/cvstd.hpp"
#include "opencv2/opencv_modules.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/core.hpp"
#include "opencv2/dnn.hpp"
#include "opencv2/cvconfig.h"
#include "stdlib.h"
#include "opencv2/opencv_modules.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/stitching/warpers.hpp"
#include "stdio.h"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/video/tracking.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/world.hpp"
#include "opencv2/flann.hpp"
#include "opencv2/dnn/dnn.hpp"
#include "opencv2/stitching.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/videoio/videoio.hpp"
#include "opencv2/videoio/videoio_c.h"
#include "opencv2/videoio/registry.hpp"
//#include "opencv2/videoio/cap_ios.h"
#include <Windows.h>
#include <stdarg.h>
#include "opencv2/core/cuda.hpp"
#include "opencv2/core/bindings_utils.hpp"
//#include "opencv2/gapi/garray.hpp"
//#include "opencv2/gapi.hpp"
#include "opencv2/calib3d/calib3d_c.h"
#include "opencv2/stitching/warpers.hpp"
//#include "opencv2/imgcodecs/ios.h"
#include "opencv2/ml/ml.hpp"
#include "opencv2/video/tracking.hpp"
#include "opencv2/flann.hpp"
#include "opencv2/photo.hpp"
#include "opencv2/stitching/detail/camera.hpp"
#include "opencv2/core/bufferpool.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/core.hpp"
#include "opencv2/core/cvstd.inl.hpp"
#include "opencv2/core/matx.hpp"
//#include "opencv2/imgproc/types_c.h"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/objdetect/detection_based_tracker.hpp"


using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	//	//Open the default video camera
	VideoCapture cap(1);
	//
	//	// if not success, exit program
	if (cap.isOpened() == false)
	{
		cout << "Cannot open the video camera" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	//
	double dWidth = cap.get(CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
	//
	cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;
	//
	//	string window_name = "My Camera Feed";
	namedWindow("444"); //create a window called "My Camera Feed"
	Mat frame1;
	bool bSuccess = cap.read(frame1); // read a new frame from video 

	while (true)
	{
		Mat frame;
		bool bSuccess = cap.read(frame); // read a new frame from video 

		//Breaking the while loop if the frames cannot be captured
		if (bSuccess == false)
		{
			cout << "Video camera is disconnected" << endl;
			cin.get(); //Wait for any key press
			break;
		}

		//show the frame in the created window
		imshow("444", frame);
		if(abs(frame1.at<uchar>(300, 300) - frame.at<uchar>(300, 300)) > 20)
		MessageBox ( NULL, "Hello World!", "Test", MB_OK );

		//		//wait for for 10 ms until any key is pressed. 
		//		//If the 'Esc' key is pressed, break the while loop.
		//		//If the any other key is pressed, continue the loop 
		//		//If any key is not pressed withing 10 ms, continue the loop 
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}
	}
	//
	return 0;
}