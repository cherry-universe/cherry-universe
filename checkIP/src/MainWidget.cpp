#include"MainWidget.hpp"
#include<QtNetwork/QHostInfo>
#include<QtCore/QList>

namespace
{
    //根据协议类型返回协议名称字符串
    QString protocolName(QAbstractSocket::NetworkLayerProtocol protocol)
    {
        QString name;
        switch(protocol)
        {
        case QAbstractSocket::IPv4Protocol:
            name="IPv4";break;
        case QAbstractSocket::IPv6Protocol:
            name="IPv6";break;
        case QAbstractSocket::AnyIPProtocol:
            name="AnyInternetProtocol";break;
        default:
            name="Unknown";
        }
        return name;
    }
}

MainWidget::MainWidget(QWidget* parent):QWidget(parent)
{
    this->setLayout(&mainLayout);
    mainLayout.addWidget(&textEdit);
    mainLayout.addWidget(&checkWidget);
    textEdit.setReadOnly(true);
    connect(&checkWidget,SIGNAL(btnLocalHostNameClicked()),this,SLOT(btnLocalHostName_clicked()));
    connect(&checkWidget,SIGNAL(btnLocalIPAddressClicked()),this,SLOT(btnLocalIPAddress_clicked()));
    connect(&checkWidget,SIGNAL(btnCheckIPClicked(QString)),this,SLOT(btnCheckIP_clicked(QString)));
}
MainWidget::~MainWidget(){}

void MainWidget::btnLocalHostName_clicked()
{//本机主机名
    textEdit.clear();
    textEdit.append("本机主机名:"+QHostInfo::localHostName());
}

void MainWidget::btnLocalIPAddress_clicked()
{//本机IP地址
    QString localHostName=QHostInfo::localHostName();//本机主机名
    btnCheckIP_clicked(localHostName);
}

void MainWidget::btnCheckIP_clicked(QString hostText)
{
    textEdit.clear();
    QHostInfo hostInfo=QHostInfo::fromName(hostText);//IP地址
    QList<QHostAddress> addressList=hostInfo.addresses();//IP地址列表

    if(!addressList.isEmpty())
    {
        textEdit.append("主机名:"+hostText);
        for(QHostAddress host:addressList)
        {
            textEdit.append("协议:"+protocolName(host.protocol()));
            textEdit.append("IP地址:"+host.toString());
        }
    }
    else
        textEdit.append("无效域名.");
}
