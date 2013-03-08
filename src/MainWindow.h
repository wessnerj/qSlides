/*
 * MainWindow.h
 *
 *  Created on: Mar 5, 2013
 *      Author: hdr
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <vector>
using std::vector;

#include <QMainWindow>
#include <QString>

namespace Ui {
	class MainWindow;
}

namespace qSlides {

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
	void updateDisplayNames();

private slots:
	void on_actionOpen_File_triggered();

private:
	Ui::MainWindow *m_pUi;
	vector<QString> m_displayNames;
};

} /* namespace qSlides */
#endif /* MAINWINDOW_H_ */
