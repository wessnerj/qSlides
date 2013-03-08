/*
 * ControlWindow.h
 *
 *  Created on: Mar 8, 2013
 *      Author: "Joseph Wessner"
 */

#ifndef CONTROLWINDOW_H_
#define CONTROLWINDOW_H_

#include <QMainWindow>

namespace Ui {
	class ControlWindow;
}

namespace qSlides {

class ControlWindow: public QMainWindow {
	Q_OBJECT

public:
	explicit ControlWindow(QWidget *parent = 0);
	~ControlWindow();

private:
	Ui::ControlWindow *ui;
};

} /* namespace qSlides */
#endif /* CONTROLWINDOW_H_ */
