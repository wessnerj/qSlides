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

#include "SlideWindow.h"
#include "PresentationController.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QRect>

namespace qSlides {

SlideWindow::SlideWindow(PresentationController *pController, QWidget *parent) : QMainWindow(parent) {
	m_pController = pController;
	m_pDocumentModel = m_pController->getDocument();
}

SlideWindow::~SlideWindow() {
}

void SlideWindow::moveToDisplay(int nDisplay, bool bFullscreen) {
	QDesktopWidget *desktop = QApplication::desktop();
	QRect screenres = desktop->screenGeometry(nDisplay);

	// moves window to the desired screen
	this->move(screenres.topLeft());

	// show window in fullscreen
	if (bFullscreen)
		this->showFullScreen();
}

void SlideWindow::on_pageNumberChange(int nNewPageNumber) {
	m_nCurrentPageNumber = nNewPageNumber;
}

void SlideWindow::resizeEvent(QResizeEvent *resizeEvent) {
	QMainWindow::resizeEvent(resizeEvent);

	// re-render slides
	on_pageNumberChange(m_nCurrentPageNumber);
}

} /* namespace qSlides */
