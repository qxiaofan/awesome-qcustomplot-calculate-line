#include "quickcalculate.h"

QuickCalculate::QuickCalculate(QWidget *parent)
: QMainWindow(parent)
{
	ui.setupUi(this);
	//对定义的数据进行初始化
	testValue1 = NULL;
	testValue2 = NULL;
	testValue3 = NULL;
	testValue4 = NULL;

	testValueT1 = NULL;
	testValueT2 = NULL;
	testValueT3 = NULL;
	testValueT4 = NULL;


	//定义输出结果
	Lower_Limit1 = NULL, Upper_Limit1 = NULL;
	Lower_Limit2 = NULL, Upper_Limit2 = NULL;
	Lower_Limit3 = NULL, Upper_Limit3 = NULL;
	Lower_Limit4 = NULL, Upper_Limit4 = NULL;


	//将这个容器中数据清空
	Point2dVec.clear();
	PntOkValue_TestValue.clear();
	PntValue_UpperLimit.clear();
	PntValue_LowerLimit.clear();

	/*double x1 = 4.48671193; double y1 = 4.50000000;
	double x2 = 5.16566440; double y2 = 5.40000000;
	double x3 = 5.16566440; double y3 = 5.30000000;
	double x4 = 5.16566440; double y4 = 5.40000000;
	double x5 = 5.35965082; double y5 = 5.70000000;
	double x6 = 5.84461688; double y6 = 6.10000000;
	double x7 = 5.84461688; double y7 = 5.90000000;
	double x8 = 5.84461688; double y8 = 6.10000000;
	double x9 = 5.84461688; double y9 = 6.20000000;
	double x10 = 6.62056256; double y10 = 6.80000000;
	double x11 = 6.71755577; double y11 = 7.10000000;
	double x12 = 6.62056256; double y12 = 6.90000000;
	double x13 = 6.91154219; double y13 = 7.20000000;
	double x14 = 7.78448109; double y14 = 8.00000000;
	double x15 = 7.687487876; double y15 = 8.20000000;
	double x16 = 7.784481086; double y16 = 8.10000000;
	double x17 = 7.97846751; double y17 = 8.30000000;
	double x18 = 8.65741998; double y18 = 8.70000000;
	double x19 = 8.46343356; double y19 = 9.00000000;
	double x20 = 9.53035887; double y20 = 9.80000000;

	stringstream sX1, sY1, sX2, sY2, sX3, sY3, sX4, sY4, sX5, sY5, sX6, sY6, sX7, sY7, sX8, sY8, sX9, sY9, sX10, sY10,
		sX11, sY11, sX12, sY12, sX13, sY13, sX14, sY14, sX15, sY15, sX16, sY16, sX17, sY17, sX18, sY18, sX19, sY19, sX20, sY20;
	sX1 << x1;	sX2 << x2;	sX3 << x3;	sX4 << x4;	sX5 << x5;	sX6 << x6;	sX7 << x7;	sX8 << x8;	sX9 << x9;	sX10 << x10;
	sX11 << x11;	sX12 << x12;	sX13 << x13;	sX14 << x14;	sX15 << x15;	sX16 << x16;	sX17 << x17;	sX18 << x18;	sX19 << x19;	sX20 << x20;

	sY1 << y1;	sY2 << y2;	sY3 << y3;	sY4 << y4;	sY5 << y5;	sY6 << y6;	sY7 << y7;	sY8 << y8;	sY9 << y9;	sY10 << y10;	sY11 << y11;	sY12 << y12;	sY13 << y13;	sY14 << y14;	sY15 << y15;	sY16 << y16;	sY17 << y17;	sY18 << y18;	sY19 << y19;	sY20 << y20;

	ui.lineEdit_X1->setText(sX1.str().c_str());
	ui.lineEdit_Y1->setText(sY1.str().c_str());

	ui.lineEdit_X2->setText(sX2.str().c_str());
	ui.lineEdit_Y2->setText(sY2.str().c_str());

	ui.lineEdit_X3->setText(sX3.str().c_str());
	ui.lineEdit_Y3->setText(sY3.str().c_str());

	ui.lineEdit_X4->setText(sX4.str().c_str());
	ui.lineEdit_Y4->setText(sY4.str().c_str());

	ui.lineEdit_X5->setText(sX5.str().c_str());
	ui.lineEdit_Y5->setText(sY5.str().c_str());

	ui.lineEdit_X6->setText(sX6.str().c_str());
	ui.lineEdit_Y6->setText(sY6.str().c_str());

	ui.lineEdit_X7->setText(sX7.str().c_str());
	ui.lineEdit_Y7->setText(sY7.str().c_str());

	ui.lineEdit_X8->setText(sX8.str().c_str());
	ui.lineEdit_Y8->setText(sY8.str().c_str());

	ui.lineEdit_X9->setText(sX9.str().c_str());
	ui.lineEdit_Y9->setText(sY9.str().c_str());

	ui.lineEdit_X10->setText(sX10.str().c_str());
	ui.lineEdit_Y10->setText(sY10.str().c_str());

	ui.lineEdit_X11->setText(sX11.str().c_str());
	ui.lineEdit_Y11->setText(sY11.str().c_str());

	ui.lineEdit_X12->setText(sX12.str().c_str());
	ui.lineEdit_Y12->setText(sY12.str().c_str());

	ui.lineEdit_X13->setText(sX13.str().c_str());
	ui.lineEdit_Y13->setText(sY13.str().c_str());

	ui.lineEdit_X14->setText(sX14.str().c_str());
	ui.lineEdit_Y14->setText(sY14.str().c_str());

	ui.lineEdit_X15->setText(sX15.str().c_str());
	ui.lineEdit_Y15->setText(sY15.str().c_str());

	ui.lineEdit_X16->setText(sX16.str().c_str());
	ui.lineEdit_Y16->setText(sY16.str().c_str());

	ui.lineEdit_X17->setText(sX17.str().c_str());
	ui.lineEdit_Y17->setText(sY17.str().c_str());

	ui.lineEdit_X18->setText(sX18.str().c_str());
	ui.lineEdit_Y18->setText(sY18.str().c_str());

	ui.lineEdit_X19->setText(sX19.str().c_str());
	ui.lineEdit_Y19->setText(sY19.str().c_str());

	ui.lineEdit_X20->setText(sX20.str().c_str());
	ui.lineEdit_Y20->setText(sY20.str().c_str());*/

}

QuickCalculate::~QuickCalculate()
{

}

//输入数据确认
void QuickCalculate::on_btnPutNumberOK_clicked()
{
	//手动输入20组数据
	QString sX1 = ui.lineEdit_X1->text();
	QString sY1 = ui.lineEdit_Y1->text();

	QString sX2 = ui.lineEdit_X2->text();
	QString sY2 = ui.lineEdit_Y2->text();

	QString sX3 = ui.lineEdit_X3->text();
	QString sY3 = ui.lineEdit_Y3->text();

	QString sX4 = ui.lineEdit_X4->text();
	QString sY4 = ui.lineEdit_Y4->text();

	QString sX5 = ui.lineEdit_X5->text();
	QString sY5 = ui.lineEdit_Y5->text();

	QString sX6 = ui.lineEdit_X6->text();
	QString sY6 = ui.lineEdit_Y6->text();

	QString sX7 = ui.lineEdit_X7->text();
	QString sY7 = ui.lineEdit_Y7->text();

	QString sX8 = ui.lineEdit_X8->text();
	QString sY8 = ui.lineEdit_Y8->text();

	QString sX9 = ui.lineEdit_X9->text();
	QString sY9 = ui.lineEdit_Y9->text();

	QString sX10 = ui.lineEdit_X10->text();
	QString sY10 = ui.lineEdit_Y10->text();

	QString sX11 = ui.lineEdit_X11->text();
	QString sY11 = ui.lineEdit_Y11->text();

	QString sX12 = ui.lineEdit_X12->text();
	QString sY12 = ui.lineEdit_Y12->text();

	QString sX13 = ui.lineEdit_X13->text();
	QString sY13 = ui.lineEdit_Y13->text();

	QString sX14 = ui.lineEdit_X14->text();
	QString sY14 = ui.lineEdit_Y14->text();

	QString sX15 = ui.lineEdit_X15->text();
	QString sY15 = ui.lineEdit_Y15->text();

	QString sX16 = ui.lineEdit_X16->text();
	QString sY16 = ui.lineEdit_Y16->text();

	QString sX17 = ui.lineEdit_X17->text();
	QString sY17 = ui.lineEdit_Y17->text();

	QString sX18 = ui.lineEdit_X18->text();
	QString sY18 = ui.lineEdit_Y18->text();

	QString sX19 = ui.lineEdit_X19->text();
	QString sY19 = ui.lineEdit_Y19->text();

	QString sX20 = ui.lineEdit_X20->text();
	QString sY20 = ui.lineEdit_Y20->text();

	//手动输入定值
	QString sTestValue1 = ui.lineEdit_TestValue1->text();
	QString sTestValue2 = ui.lineEdit_TestValue2->text();
	QString sTestValue3 = ui.lineEdit_TestValue3->text();
	QString sTestValue4 = ui.lineEdit_TestValue4->text();

	//手动输入测量值
	QString sTestValueT1 = ui.lineEdit_TestValueT1->text();
	QString sTestValueT2 = ui.lineEdit_TestValueT2->text();
	QString sTestValueT3 = ui.lineEdit_TestValueT3->text();
	QString sTestValueT4 = ui.lineEdit_TestValueT4->text();

	

	//将上述输入的QString类型数据转化成double类型
	X1 = sX1.toDouble(); Y1 = sY1.toDouble();
	X2 = sX2.toDouble(); Y2 = sY2.toDouble();
	X3 = sX3.toDouble(); Y3 = sY3.toDouble();
	X4 = sX4.toDouble(); Y4 = sY4.toDouble();
	X5 = sX5.toDouble(); Y5 = sY5.toDouble();
	X6 = sX6.toDouble(); Y6 = sY6.toDouble();
	X7 = sX7.toDouble(); Y7 = sY7.toDouble();
	X8 = sX8.toDouble(); Y8 = sY8.toDouble();
	X9 = sX9.toDouble(); Y9 = sY9.toDouble();
	X10 = sX10.toDouble(); Y10 = sY10.toDouble();
	X11 = sX11.toDouble(); Y11 = sY11.toDouble();
	X12 = sX12.toDouble(); Y12 = sY12.toDouble();
	X13 = sX13.toDouble(); Y13 = sY13.toDouble();
	X14 = sX14.toDouble(); Y14 = sY14.toDouble();
	X15 = sX15.toDouble(); Y15 = sY15.toDouble();
	X16 = sX16.toDouble(); Y16 = sY16.toDouble();
	X17 = sX17.toDouble(); Y17 = sY17.toDouble();
	X18 = sX18.toDouble(); Y18 = sY18.toDouble();
	X19 = sX19.toDouble(); Y19 = sY19.toDouble();
	X20 = sX20.toDouble(); Y20 = sY20.toDouble();

	testValue1 = sTestValue1.toDouble();
	testValue2 = sTestValue2.toDouble();
	testValue3 = sTestValue3.toDouble();
	testValue4 = sTestValue4.toDouble();

	testValueT1 = sTestValueT1.toDouble();
	testValueT2 = sTestValueT2.toDouble();
	testValueT3 = sTestValueT3.toDouble();
	testValueT4 = sTestValueT4.toDouble();

	ui.btnGetResult->setEnabled(true);

}
//输出结果
void QuickCalculate::on_btnGetResult_clicked()
{
	//将这些数据放入到数据点容器中
	Point2dVec.push_back(Point2d(X1, Y1));
	Point2dVec.push_back(Point2d(X2, Y2));
	Point2dVec.push_back(Point2d(X3, Y3));
	Point2dVec.push_back(Point2d(X4, Y4));
	Point2dVec.push_back(Point2d(X5, Y5));
	Point2dVec.push_back(Point2d(X6, Y6));
	Point2dVec.push_back(Point2d(X7, Y7));
	Point2dVec.push_back(Point2d(X8, Y8));
	Point2dVec.push_back(Point2d(X9, Y9));
	Point2dVec.push_back(Point2d(X10, Y10));
	Point2dVec.push_back(Point2d(X11, Y11));
	Point2dVec.push_back(Point2d(X12, Y12));
	Point2dVec.push_back(Point2d(X13, Y13));
	Point2dVec.push_back(Point2d(X14, Y14));
	Point2dVec.push_back(Point2d(X15, Y15));
	Point2dVec.push_back(Point2d(X16, Y16));
	Point2dVec.push_back(Point2d(X17, Y17));
	Point2dVec.push_back(Point2d(X18, Y18));
	Point2dVec.push_back(Point2d(X19, Y19));
	Point2dVec.push_back(Point2d(X20, Y20));

	//将输入的定值与测试值放入容器中
	PntOkValue_TestValue.push_back(Point2d(testValue1, testValueT1));
	PntOkValue_TestValue.push_back(Point2d(testValue2, testValueT2));
	PntOkValue_TestValue.push_back(Point2d(testValue3, testValueT3));
	PntOkValue_TestValue.push_back(Point2d(testValue4, testValueT4));

	//用数学公式的方法来计算y=ax+b的系数
	//先求xy的拔
	double sum_XY = 0;
	for (size_t i = 0; i < Point2dVec.size();i++)
	{
		sum_XY = sum_XY + Point2dVec[i].x*Point2dVec[i].y;
	}
	double averageXY = sum_XY / Point2dVec.size();
	//求x的拔
	//此处需要先计算M11=Average(x)
	double sum_x = 0;
	for (int h = 0; h < Point2dVec.size(); h++)
	{
		sum_x = sum_x + Point2dVec[h].x;
	}
	double M11 = sum_x / Point2dVec.size();
	double x_Average = M11;

	//求y的拔；
	double sum_y = 0;
	for (int h = 0; h < Point2dVec.size(); h++)
	{
		sum_y = sum_y + Point2dVec[h].y;
	}
	double y_Average = sum_y / Point2dVec.size();

    //求x^2的拔
	double sum_PowX = 0;
	for (int q = 0; q < Point2dVec.size(); q++)
	{
		sum_PowX = sum_PowX + pow(Point2dVec[q].x,2);
	}
	double PowX_Average = sum_PowX / Point2dVec.size();

	double b = (averageXY - x_Average*y_Average) / (PowX_Average - pow(x_Average, 2));
	double a = y_Average - b*x_Average;
	Pnt0.x = 0;
	Pnt0.y = a;
	k = b;


	//将数据点与拟合好的直线方程保存到D盘
	//代码如下：
	char *fname1 = "D:/DataResults.txt";
	ofstream fout1(fname1, ios::app);
	fout1 << "//输入的数组点如下：" << endl;
	fout1.close();
	for (size_t i = 0; i < Point2dVec.size(); i++)
	{
		char *fname2 = "D:/DataResults.txt";
		ofstream fout2(fname2, ios::app);
		fout2.setf(ios::fixed, ios::floatfield);//设置保留小数点后5位小数
		fout2.precision(8);
		fout2 << "第 " << i + 1 << "组点数据 " << "X: " << Point2dVec[i].x << "    " << "Y: " << Point2dVec[i].y << endl;
		fout2.close();
	}

	//拟合后的直线方程为:y=k*(x-Pnt0.x)+Pnt0.y
	char *fnameI = "D:/DataResults.txt";
	ofstream foutI(fnameI, ios::app);


	foutI << endl << "拟合后的直线方程为 y=bx+a:" << endl
		<< "y=" << k << "*x"<< "+(" << a<< ")" << endl;


	//foutI << endl << "拟合后的直线方程为 y=k(x-x0)+y0:" << endl
	//	<< "y=" << k << "*x"<< "+(" << -k*Pnt0.x + Pnt0.y << ")" << endl;

	foutI.close();


	//计算lower-limit以及upper_limit数值
	//计算R11
	//先要计算L11=sqrt(sum((y-y0)^2)/20)
	//此处需要利用拟合好的直线方程，先计算出y0;
	vector<double> yVec;
	double y = 0;
	for (int j = 0; j < Point2dVec.size(); j++)
	{
		y = k*(Point2dVec[j].x - Pnt0.x) + Pnt0.y;
		yVec.push_back(y);
	}
	double sum_DetY = 0;
	for (int m = 0; m < Point2dVec.size(); m++)
	{
		double detY = Point2dVec[m].y - yVec[m];
		sum_DetY = sum_DetY + pow(detY, 2);
	}
	double L11 = sqrt(sum_DetY / 20.0);  //此处便已计算好L11

	//此处开始计算Q11

	//针对第一个测试值计算结果
	if (testValue1 != NULL&&testValueT1 != NULL)
	{
		double sum_detX = 0;
		//先计算N9
		double N9_1 = testValue1; //可见N9是已知的值，由输入的测试值大小决定
		double N11 = pow((N9_1 - M11), 2); //此处计算出N11=x_average
		//计算P11=sum((xi-x_average)^2)
		for (size_t n = 0; n < Point2dVec.size(); n++)
		{
			double detX = pow((Point2dVec[n].x - M11), 2);
			sum_detX = sum_detX + detX;
		}
		double P11 = sum_detX;  //计算出P11;
		double Q11 = N11 / P11;
		R11_1 = 2.42311654*L11*sqrt(1 + 1.0/20.0 + Q11);
		Lower_Limit1 = k*N9_1 +a- R11_1;
		Upper_Limit1 = k*N9_1 +a+ R11_1;

		QString lowerLimit1 = QString::number(Lower_Limit1, 'd');
		QString upperLimit1 = QString::number(Upper_Limit1, 'd');
		ui.lineEdit_LowerLimit1->setText(lowerLimit1);
		ui.lineEdit_UpperLimit1->setText(upperLimit1);

		char *fname3 = "D:/DataResults.txt";
		ofstream fout3(fname3, ios::app);
		fout3 << endl << "输入的四舍五入后定值：" << testValue1 << "输入的测量值：" << testValueT1 << endl
			<< "Lower_Limit1== " << Lower_Limit1 << endl
			<< "Upper_Limit1== " << Upper_Limit1 << endl << endl;
		fout3.close();
		PntValue_UpperLimit.push_back(Point2d(testValue1, Upper_Limit1));
		PntValue_LowerLimit.push_back(Point2d(testValue1, Lower_Limit1));

	}
	
	//针对第二个测试值计算结果
	if (testValue2 != NULL&&testValueT2 != NULL)
	{
		double sum_detX = 0;
		//先计算N9
		double N9_2 = testValue2; //可见N9是已知的值，由输入的测试值大小决定
		double N11 = pow((N9_2 - M11), 2); //此处计算出N11=x_average
		//计算P11=sum((xi-x_average)^2)
		for (size_t n = 0; n < Point2dVec.size(); n++)
		{
			double detX = pow((Point2dVec[n].x - M11), 2);
			sum_detX = sum_detX + detX;
		}
		double P11 = sum_detX;  //计算出P11;
		double Q11 = N11 / P11;
		R11_2 = 2.42311654*L11*sqrt(1 + 1.0/20 + Q11);
		Lower_Limit2 = k*N9_2 + a - R11_2;
		Upper_Limit2 = k*N9_2 + a + R11_2;

		QString lowerLimit2 = QString::number(Lower_Limit2, 'd');
		QString upperLimit2 = QString::number(Upper_Limit2, 'd');
		ui.lineEdit_LowerLimit2->setText(lowerLimit2);
		ui.lineEdit_UpperLimit2->setText(upperLimit2);

		char *fname4 = "D:/DataResults.txt";
		ofstream fout4(fname4, ios::app);
		fout4 << "输入的四舍五入后定值：" << testValue2 << "输入的测量值：" << testValueT2 << endl
			<< "Lower_Limit2== " << Lower_Limit2 << endl
			<< "Upper_Limit2== " << Upper_Limit2 << endl << endl;
		fout4.close();

		PntValue_UpperLimit.push_back(Point2d(testValue2, Upper_Limit2));
		PntValue_LowerLimit.push_back(Point2d(testValue2, Lower_Limit2));

	}

	//针对第三个测试值计算结果
	if (testValue3 != NULL&&testValueT3 != NULL)
	{
		double sum_detX = 0;
		//先计算N9
		double N9_3 = testValue3; //可见N9是已知的值，由输入的测试值大小决定
		double N11 = pow((N9_3 - M11), 2); //此处计算出N11=x_average
		//计算P11=sum((xi-x_average)^2)
		for (size_t n = 0; n < Point2dVec.size(); n++)
		{
			double detX = pow((Point2dVec[n].x - M11), 2);
			sum_detX = sum_detX + detX;
		}
		double P11 = sum_detX;  //计算出P11;
		double Q11 = N11 / P11;
		R11_3 = 2.42311654*L11*sqrt(1 + 1.0/20 + Q11);
		Lower_Limit3 = k*N9_3 + a - R11_3;
		Upper_Limit3 = k*N9_3 + a + R11_3;

		QString lowerLimit3 = QString::number(Lower_Limit3, 'd');
		QString upperLimit3 = QString::number(Upper_Limit3, 'd');
		ui.lineEdit_LowerLimit3->setText(lowerLimit3);
		ui.lineEdit_UpperLimit3->setText(upperLimit3);

		char *fname5 = "D:/DataResults.txt";
		ofstream fout5(fname5, ios::app);
		fout5 << "输入的四舍五入后定值：" << testValue3 << "输入的测量值：" << testValueT3 << endl
			<< "Lower_Limit3== " << Lower_Limit3 << endl
			<< "Upper_Limit3== " << Upper_Limit3<< endl << endl;
		fout5.close();
		PntValue_UpperLimit.push_back(Point2d(testValue3, Upper_Limit3));
		PntValue_LowerLimit.push_back(Point2d(testValue3, Lower_Limit3));

	}
	//针对第四个测试值计算结果
	if (testValue4 != NULL&&testValueT4 != NULL)
	{
		double sum_detX = 0;
		//先计算N9
		double N9_4 = testValue4; //可见N9是已知的值，由输入的测试值大小决定
		double N11 = pow((N9_4 - M11), 2); //此处计算出N11=x_average
		//计算P11=sum((xi-x_average)^2)
		for (size_t n = 0; n < Point2dVec.size(); n++)
		{
			double detX = pow((Point2dVec[n].x - M11), 2);
			sum_detX = sum_detX + detX;
		}
		double P11 = sum_detX;  //计算出P11;
		double Q11 = N11 / P11;
		R11_4 = 2.42311654*L11*sqrt(1 + 1.0/20.0 + Q11);
		Lower_Limit4 = k*N9_4 + a - R11_4;
		Upper_Limit4 = k*N9_4 + a + R11_4;

		QString lowerLimit4 = QString::number(Lower_Limit4, 'd');
		QString upperLimit4 = QString::number(Upper_Limit4, 'd');
		ui.lineEdit_LowerLimit4->setText(lowerLimit4);
		ui.lineEdit_UpperLimit4->setText(upperLimit4);

		char *fname6 = "D:/DataResults.txt";
		ofstream fout6(fname6, ios::app);
		fout6 << "输入的四舍五入后定值：" << testValue4 << "输入的测量值：" << testValueT4 << endl
			<< "Lower_Limit4== " << Lower_Limit4 << endl
			<< "Upper_Limit4== " << Upper_Limit4 << endl << endl;
		fout6.close();

		PntValue_UpperLimit.push_back(Point2d(testValue4, Upper_Limit4));
		PntValue_LowerLimit.push_back(Point2d(testValue4, Lower_Limit4));

	}

	//将上述的结果，保存入容器PntValue_UpperLimit以及PntValue_LowerLimit中

	if (PntValue_UpperLimit.size() == 0||PntValue_UpperLimit.size() == 0)
	{
		QMessageBox::critical(this, GBK::ToUnicode("友情提示"), GBK::ToUnicode("输入定值与测量值，请检查"));
	}

	if (PntValue_UpperLimit.size()==1)
	{
		//则上界的直线穿过这个点，直线的斜率按照和20组数据拟合的结果相同
		PntUpper0.x = PntValue_UpperLimit[0].x;
		PntUpper0.y = PntValue_UpperLimit[0].y;
		k_Upper = k;
		PntLower0.x = PntValue_LowerLimit[0].x;
		PntLower0.y = PntValue_LowerLimit[0].y;
		k_Lower = k;
	}


	if (PntValue_LowerLimit.size()>1)
	{

		//先拟合上界线
		//用数学公式的方法来计算y=bx+a的系数
		//先求xy的拔
		double sum_XY_Upper = 0;
		for (size_t i = 0; i < PntValue_UpperLimit.size(); i++)
		{
			sum_XY_Upper = sum_XY_Upper + PntValue_UpperLimit[i].x*PntValue_UpperLimit[i].y;
		}
		double averageXY_Upper = sum_XY_Upper / PntValue_UpperLimit.size();
		//求x的拔
		//此处需要先计算M11=Average(x)
		double sum_x_Upper = 0;
		for (int h = 0; h < PntValue_UpperLimit.size(); h++)
		{
			sum_x_Upper = sum_x_Upper + PntValue_UpperLimit[h].x;
		}
		double x_Average_Upper = sum_x_Upper / PntValue_UpperLimit.size();

		//求y的拔；
		double sum_y_Upper = 0;
		for (int h = 0; h < PntValue_UpperLimit.size(); h++)
		{
			sum_y_Upper = sum_y_Upper + PntValue_UpperLimit[h].y;
		}
		double y_Average_Upper = sum_y_Upper / PntValue_UpperLimit.size();

		//求x^2的拔
		double sum_PowX_Upper = 0;
		for (int q = 0; q < PntValue_UpperLimit.size(); q++)
		{
			sum_PowX_Upper = sum_PowX_Upper + pow(PntValue_UpperLimit[q].x, 2);
		}
		double PowX_Average_Upper = sum_PowX_Upper / PntValue_UpperLimit.size();

		double b_Upper = (averageXY_Upper - x_Average_Upper*y_Average_Upper) / (PowX_Average_Upper - pow(x_Average_Upper, 2));
		double a_Upper = y_Average_Upper - b_Upper*x_Average_Upper;
		PntUpper0.x = 0;
		PntUpper0.y = a_Upper;
		k_Upper = b_Upper;

		//*************************
		//先拟合下界线
		//用数学公式的方法来计算y=bx+a的系数
		//先求xy的拔
		double sum_XY_Lower = 0;
		for (size_t i = 0; i < PntValue_LowerLimit.size(); i++)
		{
			sum_XY_Lower = sum_XY_Lower + PntValue_LowerLimit[i].x*PntValue_LowerLimit[i].y;
		}
		double averageXY_Lower = sum_XY_Lower / PntValue_LowerLimit.size();
		//求x的拔
		//此处需要先计算M11=Average(x)
		double sum_x_Lower = 0;
		for (int h = 0; h < PntValue_LowerLimit.size(); h++)
		{
			sum_x_Lower = sum_x_Lower + PntValue_LowerLimit[h].x;
		}
		double x_Average_Lower = sum_x_Lower / PntValue_LowerLimit.size();

		//求y的拔；
		double sum_y_Lower = 0;
		for (int h = 0; h < PntValue_LowerLimit.size(); h++)
		{
			sum_y_Lower = sum_y_Lower + PntValue_LowerLimit[h].y;
		}
		double y_Average_Lower = sum_y_Lower / PntValue_LowerLimit.size();

		//求x^2的拔
		double sum_PowX_Lower = 0;
		for (int q = 0; q < PntValue_LowerLimit.size(); q++)
		{
			sum_PowX_Lower = sum_PowX_Lower + pow(PntValue_LowerLimit[q].x, 2);
		}
		double PowX_Average_Lower = sum_PowX_Lower / PntValue_LowerLimit.size();

		double b_Lower = (averageXY_Lower - x_Average_Lower*y_Average_Lower) / (PowX_Average_Lower - pow(x_Average_Lower, 2));
		double a_Lower = y_Average_Lower - b_Lower*x_Average_Lower;
		PntLower0.x = 0;
		PntLower0.y = a_Lower;
		k_Lower = b_Lower;
	}
	ui.btn_ShowImg->setEnabled(true);
	ui.btnGetResult->setEnabled(false);

}
//输出拟合直线
void QuickCalculate::on_btn_ShowImg_clicked()
{
	imgshowDlg imgshowDlgModel(this);
	imgshowDlgModel.exec();
}
//退出
void QuickCalculate::on_btnExit_clicked()
{
	exit(0);
}