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

#ifndef PRESENTATIONWINDOW_H_
#define PRESENTATIONWINDOW_H_

#include <QMainWindow>

namespace Ui {
class PresentationWindow;
}

namespace qSlides {

class PresentationController;

class PresentationWindow: public QMainWindow {
Q_OBJECT

public:
	explicit PresentationWindow(PresentationController *pController,
			QWidget *parent = 0);
	~PresentationWindow();

private:
	/**
	 * Pointer to the Qt-generated UI
	 */
	Ui::PresentationWindow *m_pUi;

	PresentationController *m_pController;
};

} /* namespace qSlides */
#endif /* PRESENTATIONWINDOW_H_ */
