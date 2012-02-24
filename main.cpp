/*
 * Copyright (c) 2012 Mike Sharkey <mike@pikeaero.com>
 *
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Mike Sharkey wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 */
#include <QtGui/QApplication>
#include "opennic.h"

#include <QSystemTrayIcon>
#include <QMessageBox>
int main(int argc, char *argv[])
{
	int rc=0;
	Q_INIT_RESOURCE(opennic);
	QApplication a(argc, argv);
	if ( !QSystemTrayIcon::isSystemTrayAvailable() )
	{
		QMessageBox::critical(0, QObject::tr("OpenNic"), QObject::tr("No System Tray Detected."));
		rc = 1;
	}
	else
	{
		OpenNIC on;
		QObject::connect(&on,SIGNAL(quit()),&a,SLOT(quit()));
		rc = a.exec();
	}
	Q_CLEANUP_RESOURCE(opennic);
	return rc;
}
