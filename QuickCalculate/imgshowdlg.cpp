#include "imgshowdlg.h"
#include<algorithm>

imgshowDlg::imgshowDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.ImgQCustomPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui.ImgQCustomPlot->xAxis2, SLOT(setRange(QCPRange)));
	connect(ui.ImgQCustomPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui.ImgQCustomPlot->yAxis2, SLOT(setRange(QCPRange)));
	ui.ImgQCustomPlot->xAxis2->setVisible(true);
	ui.ImgQCustomPlot->xAxis2->setTickLabels(false);
	ui.ImgQCustomPlot->yAxis2->setVisible(true);
	ui.ImgQCustomPlot->yAxis2->setTickLabels(false);
	ui.ImgQCustomPlot->xAxis->setLabel(GBK::ToUnicode("参考方法值"));
	ui.ImgQCustomPlot->yAxis->setLabel(GBK::ToUnicode("对比方法值"));
	ui.ImgQCustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
	ui.ImgQCustomPlot->addGraph();
	//初始化
	//针对拟合直线进行初始化
	QPen pen(QColor("red"));
	ui.ImgQCustomPlot->graph()->setPen(pen); //设置点的颜色
	ui.ImgQCustomPlot->graph()->setLineStyle(QCPGraph::LineStyle::lsNone);
	ui.ImgQCustomPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 1)); //1：点的尺寸

	//针对上边界线
	ui.ImgQCustomPlot->addGraph();
	QPen penUpper(QColor("black"));
	ui.ImgQCustomPlot->graph(1)->setPen(penUpper); //设置点的颜色
	ui.ImgQCustomPlot->graph(1)->setLineStyle(QCPGraph::LineStyle::lsNone);
	ui.ImgQCustomPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 1)); //1：点的尺寸

	//针对下边界线
	ui.ImgQCustomPlot->addGraph();
	QPen penLower(QColor("black"));
	ui.ImgQCustomPlot->graph(2)->setPen(penLower); //设置点的颜色
	ui.ImgQCustomPlot->graph(2)->setLineStyle(QCPGraph::LineStyle::lsNone);
	ui.ImgQCustomPlot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 1)); //1：点的尺寸

	//针对20组数据点集
	ui.ImgQCustomPlot->addGraph();
	QPen penPnts(QColor("blue"));
	ui.ImgQCustomPlot->graph(3)->setPen(penPnts); //设置点的颜色
	ui.ImgQCustomPlot->graph(3)->setLineStyle(QCPGraph::LineStyle::lsNone);
	ui.ImgQCustomPlot->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 3)); //1：点的尺寸

	//针对四组定值与对应的测量值
	ui.ImgQCustomPlot->addGraph();
	QPen penPntsValue(QColor("red"));
	ui.ImgQCustomPlot->graph(4)->setPen(penPntsValue); //设置点的颜色
	ui.ImgQCustomPlot->graph(4)->setLineStyle(QCPGraph::LineStyle::lsNone);
	ui.ImgQCustomPlot->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 3)); //1：点的尺寸


	ui.ImgQCustomPlot->yAxis->ticker()->setTickStepStrategy(ui.ImgQCustomPlot->xAxis->ticker()->tickStepStrategy());
	//ui.ImgQCustomPlot->setBackground(Qt::GlobalColor::black);
	
}

imgshowDlg::~imgshowDlg()
{

}


//设置保存路径
void imgshowDlg::on_btnSetSavePath_clicked()
{
	imgPath = QFileDialog::getExistingDirectory(this, GBK::ToUnicode("设置图像保存路径"), "D:/", QFileDialog::Option::ShowDirsOnly);
	ui.btnShowImg->setEnabled(true);


}
//显示数据点
void imgshowDlg::on_btnShowImg_clicked()
{
	//将20组数据拟合出一条直线
	//子窗口调用父窗口中的成员变量以及成员函数
	QuickCalculate *p = (QuickCalculate *)parentWidget();
	
	//将横坐标的值放到一个数值容器中
	std::vector<double> xVec;
	for (size_t i = 0; i < p->Point2dVec.size();i++)
	{
		xVec.push_back(p->Point2dVec[i].x);
	}
	//先找出横坐标的最大最小值
	std::vector<double>::iterator biggest = std::max_element(std::begin(xVec),std::end(xVec));
	double x_MaxValue = *biggest;
	auto smallest = std::min_element(std::begin(xVec), std::end(xVec));
	double x_MinValue = *smallest;

	ui.ImgQCustomPlot->graph(0)->data().clear();
	ui.ImgQCustomPlot->graph(1)->data().clear();
	ui.ImgQCustomPlot->graph(2)->data().clear();
	ui.ImgQCustomPlot->graph(3)->data().clear();
	ui.ImgQCustomPlot->graph(4)->data().clear();
	QVector<double> x_value, y_value;
	int number = (int)(x_MaxValue - x_MinValue) / (0.01) + 1000;
	double x = x_MinValue - 5;
	double y = 0;
	for (int i = 0; i < number; i++)
	{
		x_value.push_back(x);
		y = p->k*(x - p->Pnt0.x) + p->Pnt0.y;
		y_value.push_back(y);
		x = x + 0.01;
	}
	//先绘制好拟合的直线 红色线
	//先绘制上边界
	ui.ImgQCustomPlot->graph(0)->setData(x_value,y_value);
	ui.ImgQCustomPlot->graph(0)->rescaleAxes();
	ui.ImgQCustomPlot->yAxis->setScaleRatio(ui.ImgQCustomPlot->xAxis, 1);

	//再添加两条边界线
	QVector<double> Upper_x_value, Upper_y_value;
	double Upper_X = x_MinValue - 5;
	double Upper_Y = 0;
	if (p->PntValue_LowerLimit.size()==1)
	{
		for (size_t j = 0; j < number; j++)
		{
			Upper_x_value.push_back(Upper_X);
			Upper_Y = p->k_Upper*(Upper_X-p->PntUpper0.x) + p->PntUpper0.y;
			Upper_y_value.push_back(Upper_Y);
			Upper_X = Upper_X + 0.01;
		}

	}

	if (p->PntValue_LowerLimit.size() >1)
	{
		for (size_t j = 0; j < number; j++)
		{
			Upper_x_value.push_back(Upper_X);
			Upper_Y = p->k_Upper*Upper_X + p->PntUpper0.y;
			Upper_y_value.push_back(Upper_Y);
			Upper_X = Upper_X + 0.01;
		}
	}


	ui.ImgQCustomPlot->graph(1)->setData(Upper_x_value, Upper_y_value);
	ui.ImgQCustomPlot->graph(1)->rescaleAxes();
	ui.ImgQCustomPlot->yAxis->setScaleRatio(ui.ImgQCustomPlot->xAxis, 1);

	//再绘制下边界
	QVector<double> Lower_x_value, Lower_y_value;
	double Lower_X = x_MinValue - 5;
	double Lower_Y = 0;


	if (p->PntValue_LowerLimit.size() == 1)
	{
		for (size_t j = 0; j < number; j++)
		{
			Lower_x_value.push_back(Lower_X);
			Lower_Y = p->k_Lower*(Lower_X - p->PntLower0.x) + p->PntLower0.y;
			Lower_y_value.push_back(Lower_Y);
			Lower_X = Lower_X + 0.01;
		}

	}

	if (p->PntValue_LowerLimit.size()>1)
	{
		for (size_t t = 0; t < number; t++)
		{
			Lower_x_value.push_back(Lower_X);
			Lower_Y = p->k_Lower*Lower_X + p->PntLower0.y;
			Lower_y_value.push_back(Lower_Y);
			Lower_X = Lower_X + 0.01;
		}
	}

	ui.ImgQCustomPlot->graph(2)->setData(Lower_x_value, Lower_y_value);
	ui.ImgQCustomPlot->graph(2)->rescaleAxes();
	ui.ImgQCustomPlot->yAxis->setScaleRatio(ui.ImgQCustomPlot->xAxis, 1);

	//绘制20组点数据
	QVector<double> xPnts, yPnts;
	xPnts.clear(); yPnts.clear();
	for (size_t m = 0; m < p->Point2dVec.size();m++)
	{
		xPnts.push_back(p->Point2dVec[m].x);
		yPnts.push_back(p->Point2dVec[m].y);
	}

	ui.ImgQCustomPlot->graph(3)->setData(xPnts, yPnts);
	ui.ImgQCustomPlot->graph(3)->rescaleAxes();
	ui.ImgQCustomPlot->yAxis->setScaleRatio(ui.ImgQCustomPlot->xAxis, 1);

	//绘制四组对应的定值与测量值
	QVector<double> xPntsValue, yPntsValue;
	xPntsValue.clear(); yPntsValue.clear();
	for (size_t m = 0; m < p->PntOkValue_TestValue.size(); m++)
	{
		xPntsValue.push_back(p->PntOkValue_TestValue[m].x);
		yPntsValue.push_back(p->PntOkValue_TestValue[m].y);
	}

	ui.ImgQCustomPlot->graph(4)->setData(xPntsValue, yPntsValue);
	ui.ImgQCustomPlot->graph(4)->rescaleAxes();
	ui.ImgQCustomPlot->yAxis->setScaleRatio(ui.ImgQCustomPlot->xAxis, 1);

	ui.ImgQCustomPlot->replot();
	ui.btnSaveImg->setEnabled(true);

}
//保存图片
void imgshowDlg::on_btnSaveImg_clicked()
{
	QString imgName="img.bmp";
	QString SavePath = imgPath + imgName;
	QByteArray byteA = SavePath.toLatin1();
	char *imgNameTem = byteA.data();
	ui.ImgQCustomPlot->saveBmp(imgNameTem);
}
//退出
void imgshowDlg::on_btnQuit_clicked()
{
	this->close();

}