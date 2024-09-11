QT			+=		core
QT			+=		gui
QT			+=		widgets
QT			+=		network

TEMPLATE	=		app
TARGET		=		查找IP地址

CONFIG		+=		rtti

#输入
SOURCES		+=		../src/main.cpp
HEADERS		+=		../src/MainWidget.hpp
SOURCES		+=		../src/MainWidget.cpp

HEADERS     +=      ../src/CheckWidget/CheckWidget.hpp
SOURCES     +=      ../src/CheckWidget/CheckWidget.cpp

#输出
DESTDIR		=		../out/exe		#可执行文件
MOC_DIR		=		../out/moc		#MOC中间文件
OBJECTS_DIR	=		../out/obj		#obj文件
