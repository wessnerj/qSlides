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

#include "IDocumentModel.h"

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

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

	/**
	 * Check if the chosen preferences are valid, return false otherwise
	 */
	bool validatePreferences();

	/**
	 * Enables or disables the start button according to the validation.
	 */
	void setStartEnabledStatus();

private slots:
	void on_actionOpen_File_triggered();
	void on_selectControlDisplay_currentIndexChanged(int index);
	void on_selectPresentationDisplay_currentIndexChanged(int index);
	void on_buttonStartPresentation_clicked();

private:
	/**
	 * Pointer to the Qt-generated UI
	 */
	Ui::StartWindow *m_pUi;

	/**
	 * Holds the display names of available displays
	 */
	vector<QString> m_displayNames;

	shared_ptr<IDocumentModel> m_pDocumentModel;
};

} /* namespace qSlides */
#endif /* MAINWINDOW_H_ */
