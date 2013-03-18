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

#include "PresentationWindow.h"
#include "ui_presentationWindow.h"

#include "PresentationController.h"

#include <QImage>
#include <QPixmap>

namespace qSlides {

PresentationWindow::PresentationWindow(PresentationController *pController,
		QWidget *parent) :
		SlideWindow(pController, parent), m_pUi(new Ui::PresentationWindow) {
	m_pUi->setupUi(this);
}

PresentationWindow::~PresentationWindow() {
	delete m_pUi;
}

void PresentationWindow::on_pageNumberChange(int nNewPageNumber) {
	const QRect dims = this->geometry();

	shared_ptr<IDocumentModel> pDocument = m_pController->getDocument();
	QImage renderedPage = pDocument->renderPage(nNewPageNumber, dims.width(), dims.height());

	m_pUi->labelSlide->setPixmap(QPixmap::fromImage(renderedPage));
}

} /* namespace qSlides */
