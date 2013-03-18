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

namespace qSlides {

ControlWindow::ControlWindow(PresentationController *pController, QWidget *parent) :
		SlideWindow(pController, parent), m_pUi(new Ui::ControlWindow) {
	m_pUi->setupUi(this);
}

ControlWindow::~ControlWindow() {
	delete m_pUi;
}

void ControlWindow::on_pageNumberChange(int nNewPageNumber) {
	shared_ptr<IDocumentModel> pDocument = m_pController->getDocument();

	const QRect mainDims = m_pUi->labelSlideMain->geometry();
	m_pUi->labelSlideMain->setPixmap(QPixmap::fromImage(pDocument->renderPage(nNewPageNumber, mainDims.width(), mainDims.height())));

	// TODO: Check if page nNewPageNumber+2 is available
	const QRect sideDims = m_pUi->labelSlideP1->geometry();
	m_pUi->labelSlideP1->setPixmap(QPixmap::fromImage(pDocument->renderPage(nNewPageNumber+1, sideDims.width(), sideDims.height())));
	m_pUi->labelSlideP2->setPixmap(QPixmap::fromImage(pDocument->renderPage(nNewPageNumber+2, sideDims.width(), sideDims.height())));

//	shared_ptr<IDocumentModel> pDocument = m_pController->getDocument();
//	QImage renderedPage = pDocument->renderPage(nNewPageNumber);

//	 m_pUi->labelSlide->setPixmap(QPixmap::fromImage(renderedPage));
}

} /* namespace qSlides */
