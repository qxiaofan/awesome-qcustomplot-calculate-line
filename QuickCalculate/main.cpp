#include "quickcalculate.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QuickCalculate w;
	w.show();
	return a.exec();
}
