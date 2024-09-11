#ifndef CHECKIP_MAINWIDGET_HPP_
#define CHECKIP_MAINWIDGET_HPP_

#include<QtWidgets/QWidget>
#include<QtWidgets/QTextEdit>
#include<QtWidgets/QVBoxLayout>
#include"CheckWidget/CheckWidget.hpp"

class MainWidget:public QWidget
{
	Q_OBJECT
	Q_CLASSINFO("AUTHOR","hgfugotry");
public:
	MainWidget(QWidget* parent=nullptr);
	~MainWidget();
private:
	CheckWidget checkWidget;
	QTextEdit textEdit;
	QVBoxLayout mainLayout;
private slots:
	void btnLocalHostName_clicked();
	void btnLocalIPAddress_clicked();
	void btnCheckIP_clicked(QString hostText);
};

#endif
