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

namespace qSlides {

PresentationController::PresentationController(shared_ptr<IDocumentModel> pDocumentModel, const int nControlDisplay, const int nPresentationDisplay) {
	m_pDocumentModel = pDocumentModel;
	m_nControlDisplayNumber = nControlDisplay;
	m_nPresentationDisplay = nPresentationDisplay;
}

PresentationController::~PresentationController() {

}

void PresentationController::startPresentation() {
	QRect screenres = QApplication::desktop()->screenGeometry(m_nControlDisplayNumber);
	widget->move(QPoint(screenres.x(), screenres.y()));
}

} /* namespace qSlides */
