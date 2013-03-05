/*
 * MainWindow.cpp
 *
 *  Created on: Mar 5, 2013
 *      Author: hdr
 */

#include "MainWindow.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
}

MainWindow::~MainWindow() {
	delete ui;
}

