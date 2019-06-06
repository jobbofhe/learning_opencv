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

	//1. 划线
	line(img, p1, p2, CV_RGB(255, 255, 0), 1);

	// Create a window for display.
	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("效果图", img);

	//第一个参数： 等待x ms，如果在此期间有按键按下，则立即结束并返回按下按键的
	//ASCII码，否则返回 - 1
	//如果x = 0，那么无限等待下去，直到有按键按下
	//另外，在imshow之后如果没有waitKey语句则不会正常显示图像。
	waitKey();

	//2. 画矩形框
	rectangle(img, p1, p2, CV_RGB(255, 0, 0), 1);

	imshow("效果图", img);
	waitKey();

	// 3. 画圆
	// 半径

	/*  函数原型
		void cv::circle (
		InputOutputArray    img,    //图像
		Point   center,             //圆心
		int     radius,             //半径
		const Scalar &  color,      //线的颜色
		int     thickness = 1,      //如果是正数，则为线的粗细，如果为负数则填充圆的内部
		int     lineType = LINE_8,  //线的类型
		int     shift = 0           ////点坐标中小数位数
		)
	*/
	int circle_radius = 80;
	Point circle_center = Point(150, 150);
	circle(img, circle_center, circle_radius, Scalar(0, 255, 255), 2);    //Scalar( (b), (g), (r), 0 )
	imshow("效果图", img);
	waitKey();


	// 4. 画椭圆
	/*	函数原型
		void cv::ellipse    (
		InputOutputArray    img,      //图像
		Point   center,               //椭圆中心
		Size    axes,                 //椭圆长半轴和短半轴
		double  angle,                //椭圆的旋转角度
		double  startAngle,           //椭圆弧的起始角
		double  endAngle,             //椭圆弧的结束角
		const Scalar &  color,        //线的颜色
		int     thickness = 1,        //如果是正数，则为线的粗细，如果为负数则填充椭圆的内部
		int     lineType = LINE_8,    //线的类型
		int     shift = 0             //中心坐标和半轴的小数位数
		)
	*/

	Point center = Point(150, 150);
	Size axes = Size(150, 80);
	double  angle = 45;
	//绘制0~360度，完整的椭圆
	ellipse(img, center, axes, angle, 0, 360, Scalar(125, 46, 0), 1, LINE_AA);
	//绘制0~180度，椭圆的一部分
	//ellipse(img, center, axes, angle, 0, 180, Scalar(0, 0, 255), 1, LINE_AA);
	imshow("效果图", img);
	waitKey();

	// 5. 画多边形
	/*
		void cv::polylines(
			InputOutputArray    img,    //图像
			InputArrayOfArrays  pts,    //点集
			bool    isClosed,           //true为闭合，最后一个点和第一个点连起来
			const Scalar & color,      //线的颜色
			int     thickness = 1,      //线的粗细
			int     lineType = LINE_8,  //线的类型
			int     shift = 0           //点的坐标精度
		)
	*/

	vector<Point> pt;

	pt.push_back(Point(50, 50));
	pt.push_back(Point(40, 120));
	pt.push_back(Point(20, 160));
	pt.push_back(Point(140, 240));
	pt.push_back(Point(240, 70));

	polylines(img, pt, 1, CV_RGB(0, 255, 0), 2);
	imshow("效果图", img);
	waitKey();


	// 6. 绘制文字
	/*
		void cv::putText    (
		InputOutputArray    img,             //图像
		const String &  text,                //要显示的字符串
		Point   org,                         //图片中文本字符串的左下角
		int     fontFace,                    //字体类型
		double  fontScale,                   //字体大小
		Scalar  color,                       //颜色
		int     thickness = 1,               //粗细
		int     lineType = LINE_8,           //线的类型
		bool    bottomLeftOrigin = false     //当TRUE时，图像原点位于左下角。否则，它在左上角
		)
	*/
	string str = "I am panda!";
	putText(img, str, Point(200, 300), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 1, LINE_AA);

	imshow("效果图", img);
	waitKey();

	// 创建一张图片
	//Mat srcImage(Size(300, 300), CV_8UC3, Scalar(0));

	//p1 = Point(60, 50);
	//p2 = Point(250, 200);

	//line(srcImage, p1, p2, CV_RGB(255, 0, 0), 1);
	//	
	//namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	//imshow("效果图", srcImage);
	//waitKey();

	return 0;
}
