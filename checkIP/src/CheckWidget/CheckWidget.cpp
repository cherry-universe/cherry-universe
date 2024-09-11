#include"CheckWidget.hpp"

CheckWidget::CheckWidget(QWidget* parent):QWidget(parent)
{
	this->setLy();
	this->setTx();
	connect(&btnLocalHostName,SIGNAL(clicked()),this,SIGNAL(btnLocalHostNameClicked()));
	connect(&btnLocalIPAddress,SIGNAL(clicked()),this,SIGNAL(btnLocalIPAddressClicked()));
	connect(&lineEditHost,SIGNAL(returnPressed()),this,SLOT(btnCheckIP_clicked()));
	connect(&btnCheckIP,SIGNAL(clicked()),this,SLOT(btnCheckIP_clicked()));
}
CheckWidget::~CheckWidget(){}

void CheckWidget::setLy()
{
	this->setLayout(&vL);
	vL.addWidget(&btnLocalHostName);
	vL.addWidget(&btnLocalIPAddress);
	vL.addLayout(&hL);
	hL.addWidget(&lHost);
	hL.addWidget(&lineEditHost);
	hL.addWidget(&btnCheckIP);
}
void CheckWidget::setTx()
{
	btnLocalHostName.setText("本机主机名(&N)");
	btnLocalIPAddress.setText("本机IP地址(&I)");
	lHost.setText("域名:");
	btnCheckIP.setText("查找(&C)");
}

void CheckWidget::btnCheckIP_clicked()
{
	emit btnCheckIPClicked(lineEditHost.text());
}