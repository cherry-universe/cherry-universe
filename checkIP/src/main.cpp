#include<QtWidgets/QApplication>
#include"MainWidget.hpp"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	MainWidget w;
	w.setMaximumSize(700,450);
	w.setMinimumSize(700,450);
	w.show();
	return app.exec();
}
