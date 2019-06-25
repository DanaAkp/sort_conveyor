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
	// получаем любую подключённую камеру
	CvCapture* capture= cvCreateCameraCapture(1); //cvCaptureFromCAM( 0 );
//	assert(capture);

	//cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 640);//1280); 
	//cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 480);//960); 

	// узнаем ширину и высоту кадра
	double width = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
	double height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
	printf("[i] %.0f x %.0f\n", width, height);

	IplImage* frame = 0;

	cvNamedWindow("capture", CV_WINDOW_AUTOSIZE);

	printf("[i] press Enter for capture image and Esc for quit!\n\n");

	int counter = 0;
	char filename[512];

	while (true) {
		// получаем кадр
		frame = cvQueryFrame(capture);

		// показываем
		cvShowImage("capture", frame);

		char c = cvWaitKey(33);
		if (c == 27) { // нажата ESC
			break;
		}
		else if (c == 13) { // Enter
				// сохраняем кадр в файл
			printf(filename, "Image%d.jpg", counter);
			printf("[i] capture... %s\n", filename);
			//cvSaveImage(filename, frame);
			counter++;
		}
	}
	// освобождаем ресурсы
	cvReleaseCapture(&capture);
	cvDestroyWindow("capture");
	return 0;
}