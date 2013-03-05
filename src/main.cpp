/*
 * main.cpp
 *
 *  Created on: Mar 5, 2013
 *      Author: Joseph Wessner <hdr@meetr.de>
 */

#include <QtGui/QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
