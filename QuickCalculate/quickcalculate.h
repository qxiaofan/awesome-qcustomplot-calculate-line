#ifndef QUICKCALCULATE_H
#define QUICKCALCULATE_H

#include<QFileDialog>
#include<QMessageBox>

#include<vector>
#include<QDebug>
//第三方库
#include"qcustomplot.h"
#include<opencv2/opencv.hpp>

#include <QtWidgets/QMainWindow>
#include "ui_quickcalculate.h"

#include"GBK.h"
#include"fstream"
#include "imgshowdlg.h"


using namespace std;
using namespace cv;

class QuickCalculate : public QMainWindow
{
	Q_OBJECT

public:
	QuickCalculate(QWidget *parent = 0);
	~QuickCalculate();

private:
	Ui::QuickCalculateClass ui;

private slots:
	//输入数据确认
	void on_btnPutNumberOK_clicked();
	//输出结果
	void on_btnGetResult_clicked();
	//输出拟合直线
	void on_btn_ShowImg_clicked();
	//退出
	void on_btnExit_clicked();

public:
	//定义待输入的20个数据变量
	double X1, Y1;
	double X2, Y2;
	double X3, Y3;
	double X4, Y4;
	double X5, Y5;
	double X6, Y6;
	double X7, Y7;
	double X8, Y8;
	double X9, Y9;
	double X10, Y10;
	double X11, Y11;
	double X12, Y12;
	double X13, Y13;
	double X14, Y14;
	double X15, Y15;
	double X16, Y16;
	double X17, Y17;
	double X18, Y18; 
	double X19, Y19;
	double X20, Y20;
	//定义待输入的测试值
	double testValue1, testValue2, testValue3, testValue4;
	double testValueT1, testValueT2, testValueT3, testValueT4;

	//定义输出结果
	double Lower_Limit1, Upper_Limit1;
	double Lower_Limit2, Upper_Limit2;
	double Lower_Limit3, Upper_Limit3;
	double Lower_Limit4, Upper_Limit4;

	double R11_1, R11_2, R11_3, R11_4;



	//申明一个容器，存放20组数据点
	std::vector<Point2d> Point2dVec;

	//申明一个容器，存放输入的四个定值以及对应的测量值
	std::vector<Point2d> PntOkValue_TestValue;

	//申明一个容器，存放输入的四个定值以及对应的Upper_limit
	std::vector<Point2d> PntValue_UpperLimit;

	//申明一个容器，存放输入的四个定值以及对应的Lower_Limit
	std::vector<Point2d> PntValue_LowerLimit;

	//存放20组数据拟合好的直线必经过的一个点
	 cv::Point2d Pnt0;
	//存放20组数据拟合后的直线斜率
	double k;

	//存放上边界拟合直线必经过的点
	cv::Point2d PntUpper0;
	//存放上边界拟合直线的斜率
	double k_Upper;

	//存放下边界拟合直线必经过的点
	cv::Point2d PntLower0;
	//存放上边界拟合直线的斜率
	double k_Lower;



};

#endif // QUICKCALCULATE_H
