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

#ifndef CONTROLWINDOW_H_
#define CONTROLWINDOW_H_

#include "SlideWindow.h"

namespace Ui {
class ControlWindow;
}

namespace qSlides {
/**
 * The ControlWindow shows the actual and upcoming slides.
 */
class ControlWindow: public SlideWindow {
Q_OBJECT

public:
	explicit ControlWindow(PresentationController *pController,
			QWidget *parent = 0);
	~ControlWindow();

	void on_pageNumberChange(int nNewPageNumber);

private slots:
	/**
	 * This method is called if the previous slide action is triggered.
	 */
	void on_actionPrev_triggered();
	/**
	 * This method is called if the next slide action is triggered.
	 */
	void on_actionNext_triggered();

private:
	/**
	 * Pointer to the Qt-generated UI
	 */
	Ui::ControlWindow *m_pUi;
};

} /* namespace qSlides */
#endif /* CONTROLWINDOW_H_ */
