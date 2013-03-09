/*
 * qSlides - Dual screen presentation tool for PDF slides
 * Copyright (C) 2013 Joseph Wessner
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <vector>
using std::vector;

#include <QMainWindow>
#include <QString>

namespace Ui {
class StartWindow;
}

namespace qSlides {

/**
 * The StartWindow is used to setup the presentation.
 */
class StartWindow: public QMainWindow {
Q_OBJECT

public:
	explicit StartWindow(QWidget *parent = 0);
	~StartWindow();

protected:
	/**
	 * Refresh the display select boxes with currently available displays
	 */
	void updateDisplayNames();

private slots:
	void on_actionOpen_File_triggered();

private:
	/**
	 * Pointer to the Qt-generated UI
	 */
	Ui::StartWindow *m_pUi;
	/**
	 * Holds the display names of available displays
	 */
	vector<QString> m_displayNames;
};

} /* namespace qSlides */
#endif /* MAINWINDOW_H_ */
