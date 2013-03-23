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

#include "IDocumentModel.h"

#include <QMainWindow>

#include <memory>
using std::shared_ptr;

namespace qSlides {

class PresentationController;

class SlideWindow : public QMainWindow {
Q_OBJECT

public:
	/**
	 * Default constructor, sets member variables and calls parent constructor.
	 *
	 * @param pController	PresentationController, which controls this window
	 * @param parent		Qt parent widget
	 */
	SlideWindow(PresentationController *pController, QWidget *parent = 0);
	~SlideWindow();

	/**
	 * Moves the window to given display and toggles to fullscreen.
	 *
	 * @param nDisplay		Display number to which the window should be moved
	 * @param bFullscreen	Whether or not the window should switch to fullscreen
	 */
	void moveToDisplay(int nDisplay, bool bFullscreen = true);

	/**
	 * This method gets called by the PresentationController, when the slide changes.
	 *
	 * @param nNewPageNumber	Page number of the current main slide.
	 */
	virtual void on_pageNumberChange(int nNewPageNumber);

	/**
	 * Override resizeEvent to get notified if window is resized.
	 *
	 * @param resizeEvent
	 */
	void resizeEvent(QResizeEvent *resizeEvent);

protected:
	/**
	 * Override close event to trigger closing of all windows through the PresentationController.
	 *
	 * @param closeEvent
	 */
	void closeEvent(QCloseEvent *closeEvent);

protected:
	/**
	 * Access to the PresentationController
	 */
	PresentationController *m_pController;

	/**
	 * Access to the DocumentModel
	 */
	shared_ptr<IDocumentModel> m_pDocumentModel;

	/**
	 * Page number of the currently shown slide.
	 */
	int m_nCurrentPageNumber;

private:
	/**
	 * This attribute determines if window closing is already in progress
	 */
	bool m_bIsClosing = false;
};

} /* namespace qSlides */
#endif /* SLIDEWINDOW_H_ */
