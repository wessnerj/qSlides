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

#include "StartWindow.h"
#include "ui_startWindow.h"

#include "IDocumentModel.h"

#include "PdfModel.h"

#include <memory>
using std::make_shared;
using std::static_pointer_cast;

#include "poppler-qt4.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QDesktopWidget>
#include <QtDebug>

namespace qSlides {

StartWindow::StartWindow(QWidget *parent) :
		QMainWindow(parent), m_pUi(new Ui::StartWindow) {
	m_pUi->setupUi(this);
	m_pDocumentModel = nullptr;

	updateDisplayNames();
}

StartWindow::~StartWindow() {
	delete m_pUi;
	m_pUi = nullptr;
}

void StartWindow::updateDisplayNames() {
	QDesktopWidget *desktop = QApplication::desktop();

	m_displayNames.clear();

	const int currentControlDisplay =
			m_pUi->selectControlDisplay->currentIndex();
	const int currentPresentationDisplay =
			m_pUi->selectPresentationDisplay->currentIndex();

	m_pUi->selectControlDisplay->clear();
	m_pUi->selectPresentationDisplay->clear();

	const int nScreenCount = desktop->screenCount();
	for (int i = 0; i < nScreenCount; i++) {
		const QRect oRect = desktop->screenGeometry(i);
		const QString displayString = tr("Display %1 (%2x%3)").arg(
				QString::number(i), QString::number(oRect.width()),
				QString::number(oRect.height()));

		m_displayNames.push_back(displayString);

		m_pUi->selectControlDisplay->addItem(displayString);
		m_pUi->selectPresentationDisplay->addItem(displayString);
	}

	if (-1 < currentControlDisplay
			&& currentControlDisplay < (int) m_displayNames.size())
		m_pUi->selectControlDisplay->setCurrentIndex(currentControlDisplay);
	else
		m_pUi->selectControlDisplay->setCurrentIndex(
				desktop->screenNumber(this));

	if (-1 < currentPresentationDisplay
			&& currentPresentationDisplay < (int) m_displayNames.size())
		m_pUi->selectPresentationDisplay->setCurrentIndex(
				currentPresentationDisplay);
	else
		m_pUi->selectPresentationDisplay->setCurrentIndex(0);
}

bool StartWindow::validatePreferences() {
	// Return false if no (valid) document is selected
	if (nullptr == m_pDocumentModel)
		return false;

	QDesktopWidget *desktop = QApplication::desktop();
	const int nScreenCount = desktop->screenCount();

	const int currentControlDisplay =
			m_pUi->selectControlDisplay->currentIndex();
	const int currentPresentationDisplay =
			m_pUi->selectPresentationDisplay->currentIndex();

	// Return only true, if both displays exist and are different
	return (-1 < currentControlDisplay && -1 < currentPresentationDisplay
			&& currentControlDisplay < nScreenCount
			&& currentPresentationDisplay < nScreenCount
			&& currentControlDisplay != currentPresentationDisplay);
}

void StartWindow::setStartEnabledStatus() {
	m_pUi->buttonStartPresentation->setEnabled(validatePreferences());
}

void StartWindow::on_actionOpen_File_triggered() {
	// Open FileDialog to get absolute file path
	const QString oAbsolutFileName = QFileDialog::getOpenFileName(this,
			tr("Open File"), "", tr("PDF Documents (*.pdf)"));

	// Nothing to do if user has aborted
	if (oAbsolutFileName.isEmpty())
		return;

	// try to load the document
	try {
		m_pDocumentModel = static_pointer_cast<IDocumentModel>(make_shared<PdfModel> (oAbsolutFileName));
	} catch (eDocumentLoadException e) {
		// TODO: Show error message
		m_pDocumentModel = nullptr;
		m_pUi->labelFilename->setText(tr("no file selected"));
		return;
	}

	// show file name
	m_pUi->labelFilename->setText(*(m_pDocumentModel->getFileName()));

	// Enable start button?
	setStartEnabledStatus();
}

void StartWindow::on_selectControlDisplay_currentIndexChanged(int index) {
	// Enable start button?
	setStartEnabledStatus();
}

void StartWindow::on_selectPresentationDisplay_currentIndexChanged(int index) {
	// Enable start button?
	setStartEnabledStatus();
}

void StartWindow::on_buttonStartPresentation_clicked() {
	qDebug() << "StartWindow::on_buttonStartPresentation_clicked()";
}

} /* namespace qSlides */
