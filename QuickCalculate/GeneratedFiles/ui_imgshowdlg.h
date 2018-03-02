/********************************************************************************
** Form generated from reading UI file 'imgshowdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGSHOWDLG_H
#define UI_IMGSHOWDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_imgshowDlg
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSetSavePath;
    QPushButton *btnShowImg;
    QPushButton *btnSaveImg;
    QPushButton *btnQuit;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCustomPlot *ImgQCustomPlot;

    void setupUi(QDialog *imgshowDlg)
    {
        if (imgshowDlg->objectName().isEmpty())
            imgshowDlg->setObjectName(QStringLiteral("imgshowDlg"));
        imgshowDlg->resize(965, 790);
        gridLayout_2 = new QGridLayout(imgshowDlg);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(9);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSetSavePath = new QPushButton(imgshowDlg);
        btnSetSavePath->setObjectName(QStringLiteral("btnSetSavePath"));

        horizontalLayout->addWidget(btnSetSavePath);

        btnShowImg = new QPushButton(imgshowDlg);
        btnShowImg->setObjectName(QStringLiteral("btnShowImg"));
        btnShowImg->setEnabled(false);

        horizontalLayout->addWidget(btnShowImg);

        btnSaveImg = new QPushButton(imgshowDlg);
        btnSaveImg->setObjectName(QStringLiteral("btnSaveImg"));
        btnSaveImg->setEnabled(false);

        horizontalLayout->addWidget(btnSaveImg);

        btnQuit = new QPushButton(imgshowDlg);
        btnQuit->setObjectName(QStringLiteral("btnQuit"));

        horizontalLayout->addWidget(btnQuit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(imgshowDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ImgQCustomPlot = new QCustomPlot(groupBox);
        ImgQCustomPlot->setObjectName(QStringLiteral("ImgQCustomPlot"));

        gridLayout->addWidget(ImgQCustomPlot, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(imgshowDlg);

        QMetaObject::connectSlotsByName(imgshowDlg);
    } // setupUi

    void retranslateUi(QDialog *imgshowDlg)
    {
        imgshowDlg->setWindowTitle(QApplication::translate("imgshowDlg", "imgshowDlg", Q_NULLPTR));
        btnSetSavePath->setText(QApplication::translate("imgshowDlg", "\350\256\276\347\275\256\350\267\257\345\276\204", Q_NULLPTR));
        btnShowImg->setText(QApplication::translate("imgshowDlg", "\345\217\257\350\247\206\345\214\226", Q_NULLPTR));
        btnSaveImg->setText(QApplication::translate("imgshowDlg", "\344\277\235\345\255\230\345\233\276\347\211\207", Q_NULLPTR));
        btnQuit->setText(QApplication::translate("imgshowDlg", "\351\200\200\345\207\272", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("imgshowDlg", "\345\233\276\345\275\242\346\230\276\347\244\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class imgshowDlg: public Ui_imgshowDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGSHOWDLG_H
