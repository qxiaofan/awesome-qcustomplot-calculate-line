#ifndef IMGSHOWDLG_H
#define IMGSHOWDLG_H

#include <QDialog>
#include "ui_imgshowdlg.h"
#include "quickcalculate.h"

class imgshowDlg : public QDialog
{
	Q_OBJECT

public:
	imgshowDlg(QWidget *parent = 0);
	~imgshowDlg();

private:
	Ui::imgshowDlg ui;

private slots:
    //设置保存路径
   void on_btnSetSavePath_clicked();
    //显示数据点
   void on_btnShowImg_clicked();
   //保存图片
   void on_btnSaveImg_clicked();
   //退出
   void on_btnQuit_clicked();

public:
	QString imgPath;


};

#endif // IMGSHOWDLG_H
