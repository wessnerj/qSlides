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

#include "PresentationController.h"

#include <QRect>
#include <QApplication>

#include <memory>
using std::make_shared;

namespace qSlides {

PresentationController::PresentationController() {
	m_pDocumentModel = nullptr;
	m_nControlDisplayNumber = -1;
	m_nPresentationDisplay = -1;
}

PresentationController::~PresentationController() {

}

void PresentationController::start() {
	m_pStartWindow = make_shared<StartWindow>(this);
	m_pStartWindow->show();

//	QRect screenres = QApplication::desktop()->screenGeometry(m_nControlDisplayNumber);
//	widget->move(QPoint(screenres.x(), screenres.y()));
}

void PresentationController::startPresentation() {
	// close start window
	m_pStartWindow->close();

	// Open control window
	m_pControlWindow = make_shared<ControlWindow>(this);
	m_pControlWindow->show();
//	 m_pControlWindow->moveToDisplay(m_nControlDisplayNumber);

	// Open presentation window
	m_pPresentationWindow = make_shared<PresentationWindow>(this);
	m_pPresentationWindow->show();
	m_pPresentationWindow->moveToDisplay(m_nPresentationDisplay);

	m_pPresentationWindow->on_pageNumberChange(0);
}

void PresentationController::setDocument(shared_ptr<IDocumentModel> pDocument) {
	m_pDocumentModel = pDocument;
}

void PresentationController::setControlDisplay(int nDisplay) {
	m_nControlDisplayNumber = nDisplay;
}

void PresentationController::setPresentationDisplay(int nDisplay) {
	m_nPresentationDisplay = nDisplay;
}

shared_ptr<IDocumentModel> PresentationController::getDocument() {
	return m_pDocumentModel;
}

} /* namespace qSlides */
