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

#include "ControlWindow.h"
#include "ui_controlWindow.h"

#include "PresentationController.h"

#include <QImage>
#include <QPixmap>
#include <QDebug>

namespace qSlides {

ControlWindow::ControlWindow(PresentationController *pController, QWidget *parent) :
		SlideWindow(pController, parent), m_pUi(new Ui::ControlWindow) {
	m_pUi->setupUi(this);
}

ControlWindow::~ControlWindow() {
	delete m_pUi;
}

void ControlWindow::on_pageNumberChange(int nNewPageNumber) {
	SlideWindow::on_pageNumberChange(nNewPageNumber);

	// Render main slide
	const QRect mainDims = m_pUi->labelSlideMain->geometry();
	m_pUi->labelSlideMain->setPixmap(QPixmap::fromImage(m_pDocumentModel->renderPage(nNewPageNumber, mainDims.width(), mainDims.height())));

	// Get number of total slides
	const int nNumberOfPages = m_pDocumentModel->getNumberOfPages();

	// Update actual slide number
	m_pUi->labelSlideStatus->setText(tr("Slide %1 of %2").arg(m_nCurrentPageNumber+1).arg(nNumberOfPages));

	// Show next slide
	if (m_nCurrentPageNumber+1 < nNumberOfPages) {
		const QRect sideDims = m_pUi->labelSlideP1->geometry();
		m_pUi->labelSlideP1->setPixmap(QPixmap::fromImage(m_pDocumentModel->renderPage(m_nCurrentPageNumber+1, sideDims.width(), sideDims.height())));
	} else {
		m_pUi->labelSlideP1->clear();
	}

	// Show slide after next slide
	if (m_nCurrentPageNumber+2 < nNumberOfPages) {
		const QRect sideDims = m_pUi->labelSlideP1->geometry();
		m_pUi->labelSlideP2->setPixmap(QPixmap::fromImage(m_pDocumentModel->renderPage(m_nCurrentPageNumber+2, sideDims.width(), sideDims.height())));
	} else {
		m_pUi->labelSlideP2->clear();
	}
}

void ControlWindow::on_actionPrev_triggered() {
	m_pController->showPrevSlide();
}

void ControlWindow::on_actionNext_triggered() {
	m_pController->showNextSlide();
}

} /* namespace qSlides */
