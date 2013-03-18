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

#ifndef PRESENTATIONCONTROLLER_H_
#define PRESENTATIONCONTROLLER_H_

#include "IDocumentModel.h"

#include "StartWindow.h"
#include "ControlWindow.h"
#include "PresentationWindow.h"

#include <memory>
using std::shared_ptr;

namespace qSlides {

class PresentationController {
public:
	PresentationController();
	virtual ~PresentationController();

	void start();
	void startPresentation();

	void setDocument(shared_ptr<IDocumentModel> pDocument);
	void setControlDisplay(int nDisplay);
	void setPresentationDisplay(int nPresentationDisplay);

	shared_ptr<IDocumentModel> getDocument();

protected:
	shared_ptr<IDocumentModel> m_pDocumentModel;
	int m_nControlDisplayNumber;
	int m_nPresentationDisplay;

	shared_ptr<StartWindow> 		m_pStartWindow;
	shared_ptr<ControlWindow>		m_pControlWindow;
	shared_ptr<PresentationWindow>	m_pPresentationWindow;
};

} /* namespace qSlides */
#endif /* PRESENTATIONCONTROLLER_H_ */
