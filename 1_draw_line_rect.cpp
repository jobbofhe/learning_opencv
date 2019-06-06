#include<iostream>  
#include<vector>  
#include<opencv2/opencv.hpp>  

using namespace cv;
using namespace std;

int main_4()
{
	Mat img = imread("E:\\images\\opencv_test\\panda.jpg");
	Point p1 = Point(20, 50);
	Point p2 = Point(250, 200);

	//1. ����
	line(img, p1, p2, CV_RGB(255, 255, 0), 1);

	// Create a window for display.
	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Ч��ͼ", img);

	//��һ�������� �ȴ�x ms������ڴ��ڼ��а������£����������������ذ��°�����
	//ASCII�룬���򷵻� - 1
	//���x = 0����ô���޵ȴ���ȥ��ֱ���а�������
	//���⣬��imshow֮�����û��waitKey����򲻻�������ʾͼ��
	waitKey();

	//2. �����ο�
	rectangle(img, p1, p2, CV_RGB(255, 0, 0), 1);

	imshow("Ч��ͼ", img);
	waitKey();

	// 3. ��Բ
	// �뾶

	/*  ����ԭ��
		void cv::circle (
		InputOutputArray    img,    //ͼ��
		Point   center,             //Բ��
		int     radius,             //�뾶
		const Scalar &  color,      //�ߵ���ɫ
		int     thickness = 1,      //�������������Ϊ�ߵĴ�ϸ�����Ϊ���������Բ���ڲ�
		int     lineType = LINE_8,  //�ߵ�����
		int     shift = 0           ////��������С��λ��
		)
	*/
	int circle_radius = 80;
	Point circle_center = Point(150, 150);
	circle(img, circle_center, circle_radius, Scalar(0, 255, 255), 2);    //Scalar( (b), (g), (r), 0 )
	imshow("Ч��ͼ", img);
	waitKey();


	// 4. ����Բ
	/*	����ԭ��
		void cv::ellipse    (
		InputOutputArray    img,      //ͼ��
		Point   center,               //��Բ����
		Size    axes,                 //��Բ������Ͷ̰���
		double  angle,                //��Բ����ת�Ƕ�
		double  startAngle,           //��Բ������ʼ��
		double  endAngle,             //��Բ���Ľ�����
		const Scalar &  color,        //�ߵ���ɫ
		int     thickness = 1,        //�������������Ϊ�ߵĴ�ϸ�����Ϊ�����������Բ���ڲ�
		int     lineType = LINE_8,    //�ߵ�����
		int     shift = 0             //��������Ͱ����С��λ��
		)
	*/

	Point center = Point(150, 150);
	Size axes = Size(150, 80);
	double  angle = 45;
	//����0~360�ȣ���������Բ
	ellipse(img, center, axes, angle, 0, 360, Scalar(125, 46, 0), 1, LINE_AA);
	//����0~180�ȣ���Բ��һ����
	//ellipse(img, center, axes, angle, 0, 180, Scalar(0, 0, 255), 1, LINE_AA);
	imshow("Ч��ͼ", img);
	waitKey();

	// 5. �������
	/*
		void cv::polylines(
			InputOutputArray    img,    //ͼ��
			InputArrayOfArrays  pts,    //�㼯
			bool    isClosed,           //trueΪ�պϣ����һ����͵�һ����������
			const Scalar & color,      //�ߵ���ɫ
			int     thickness = 1,      //�ߵĴ�ϸ
			int     lineType = LINE_8,  //�ߵ�����
			int     shift = 0           //������꾫��
		)
	*/

	vector<Point> pt;

	pt.push_back(Point(50, 50));
	pt.push_back(Point(40, 120));
	pt.push_back(Point(20, 160));
	pt.push_back(Point(140, 240));
	pt.push_back(Point(240, 70));

	polylines(img, pt, 1, CV_RGB(0, 255, 0), 2);
	imshow("Ч��ͼ", img);
	waitKey();


	// 6. ��������
	/*
		void cv::putText    (
		InputOutputArray    img,             //ͼ��
		const String &  text,                //Ҫ��ʾ���ַ���
		Point   org,                         //ͼƬ���ı��ַ��������½�
		int     fontFace,                    //��������
		double  fontScale,                   //�����С
		Scalar  color,                       //��ɫ
		int     thickness = 1,               //��ϸ
		int     lineType = LINE_8,           //�ߵ�����
		bool    bottomLeftOrigin = false     //��TRUEʱ��ͼ��ԭ��λ�����½ǡ������������Ͻ�
		)
	*/
	string str = "I am panda!";
	putText(img, str, Point(200, 300), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 1, LINE_AA);

	imshow("Ч��ͼ", img);
	waitKey();

	// ����һ��ͼƬ
	//Mat srcImage(Size(300, 300), CV_8UC3, Scalar(0));

	//p1 = Point(60, 50);
	//p2 = Point(250, 200);

	//line(srcImage, p1, p2, CV_RGB(255, 0, 0), 1);
	//	
	//namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	//imshow("Ч��ͼ", srcImage);
	//waitKey();

	return 0;
}
