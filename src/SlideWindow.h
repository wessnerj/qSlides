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

#ifndef SLIDEWINDOW_H_
#define SLIDEWINDOW_H_

#include <QMainWindow>

namespace qSlides {

class PresentationController;

class SlideWindow : public QMainWindow {
Q_OBJECT

public:
	SlideWindow(PresentationController *pController, QWidget *parent = 0);
	~SlideWindow();

	void moveToDisplay(int nDisplay, bool bFullscreen = true);

	virtual void on_pageNumberChange(int nNewPageNumber) = 0;

protected:
	PresentationController *m_pController;
};

} /* namespace qSlides */
#endif /* SLIDEWINDOW_H_ */
