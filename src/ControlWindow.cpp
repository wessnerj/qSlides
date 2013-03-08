/*
 * ControlWindow.cpp
 *
 *  Created on: Mar 8, 2013
 *      Author: "Joseph Wessner"
 */

#include "ControlWindow.h"
#include "ui_controlWindow.h"

namespace qSlides {

ControlWindow::ControlWindow(QWidget *parent) :
		QMainWindow(parent), ui(new Ui::ControlWindow) {
	ui->setupUi(this);
}

ControlWindow::~ControlWindow() {
	delete ui;
}

} /* namespace qSlides */
