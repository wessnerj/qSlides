/*
 * MainWindow.h
 *
 *  Created on: Mar 5, 2013
 *      Author: hdr
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_actionOpen_File_triggered();

private:
	Ui::MainWindow *ui;
};

#endif /* MAINWINDOW_H_ */
