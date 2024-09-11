#ifndef CHECKIP_CHECKWIDGET_HPP_
#define CHECKIP_CHECKWIDGET_HPP_

#include<QtWidgets/QWidget>
#include<QtWidgets/QVBoxLayout>
#include<QtWidgets/QHBoxLayout>
#include<QtWidgets/QPushButton>
#include<QtWidgets/QLineEdit>
#include<QtWidgets/QLabel>

class CheckWidget:public QWidget
{
	Q_OBJECT
	Q_CLASSINFO("AUTHOR","hgfugotry");
public:
	CheckWidget(QWidget* parent=nullptr);
	~CheckWidget();
private:
	QVBoxLayout vL;
	QPushButton btnLocalHostName;
	QPushButton btnLocalIPAddress;
	QHBoxLayout hL;
	QLabel lHost;
	QLineEdit lineEditHost;
	QPushButton btnCheckIP;
	void setLy();
	void setTx();
private slots:
	void btnCheckIP_clicked();
signals:
	void btnLocalHostNameClicked();
	void btnLocalIPAddressClicked();
	void btnCheckIPClicked(QString hostText);
};

#endif
