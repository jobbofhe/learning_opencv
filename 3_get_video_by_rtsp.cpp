/*
 * rtsp获取视频流
 *
 */
#include <iostream>
#include<fstream>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap;
	Mat Camera_CImg;
	Mat Camera_GImg;

	string rtsp = "rtsp://admin:admin12345@192.168.103.211:554/Streaming/Channels/101?transportmode=unicast";
	cap.open(rtsp);

	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 1920);

	if (!cap.isOpened())
	{
		return 1920;
	}

	int i = 10;
	while (1)
	{
		cap >> Camera_CImg;

		if (Camera_CImg.empty())
		{
			std::cout << "no stream..." << std::endl;
			break;
		}

		cvtColor(Camera_CImg, Camera_GImg, CV_RGB2GRAY);

		// 写一条 弹幕
		string str = "I am an apple!";
		putText(Camera_CImg, str, Point(i, 300), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 1, LINE_AA);
		i += 10;
		if (i > 1900)
		{
			i = 10;
		}
		
		namedWindow("video");//窗口
		imshow("input", Camera_CImg);

		// 展示灰度视频
		//namedWindow("video-gray");//窗口
		//imshow("input", Camera_GImg);

		if (cvWaitKey(10) == 'q')
		{
			break;
		}
	}

	system("pause");

	return 0;
}