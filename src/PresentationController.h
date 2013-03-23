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

/**
 * Controller for the presentation. Manages the Start-, Control- and PresentationWindow
 */
class PresentationController {
public:
	PresentationController();
	virtual ~PresentationController();

	/**
	 * Starts with the StartWindow
	 */
	void start();
	/**
	 * Starts the presentation if Control- and PresentationWindow
	 */
	void startPresentation();

	/**
	 * Setter for document model.
	 *
	 * @param pDocument
	 */
	void setDocument(shared_ptr<IDocumentModel> pDocument);
	/**
	 * Setter for control display
	 * @param nDisplay	number of display, where the ControlWindow should be shown.
	 */
	void setControlDisplay(int nDisplay);
	/**
	 * Setter for presentation display
	 * @param nPresentationDisplay	number of display, where the PresentationWindow should be shown.
	 */
	void setPresentationDisplay(int nPresentationDisplay);

	/**
	 * Displays the next slide.
	 */
	void showNextSlide();
	/**
	 * Displays the previous slide.
	 */
	void showPrevSlide();
	/**
	 * Displays slide with given page number.
	 *
	 * @param nPageNumber	page number of slide to be shown
	 */
	void showSlide(int nPageNumber);

	/**
	 * Closes all windows and exits the application.
	 */
	void exit();

	/**
	 * Getter for document model
	 * @return Pointer to document model
	 */
	shared_ptr<IDocumentModel> getDocument();

protected:
	/**
	 * PageNumber of current slide
	 */
	int m_nCurrentPageNumber;

	/**
	 * Access to the DocumentModel
	 */
	shared_ptr<IDocumentModel> m_pDocumentModel;

	/**
	 * DisplayNumber of control window
	 */
	int m_nControlDisplayNumber;
	/**
	 * DisplayNumber of presentation window
	 */
	int m_nPresentationDisplay;

	/**
	 * Access to StartWindow
	 */
	shared_ptr<StartWindow> 		m_pStartWindow;
	/**
	 * Access to ControlWindow
	 */
	shared_ptr<ControlWindow>		m_pControlWindow;
	/**
	 * Access to PresentationWindow
	 */
	shared_ptr<PresentationWindow>	m_pPresentationWindow;
};

} /* namespace qSlides */
#endif /* PRESENTATIONCONTROLLER_H_ */
