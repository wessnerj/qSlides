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

#include <iostream>
using std::cout;
using std::endl;

#include "poppler-qt4.h"

#include <QFileDialog>
#include <QDesktopWidget>

namespace qSlides {

StartWindow::StartWindow(QWidget *parent) :
		QMainWindow(parent), m_pUi(new Ui::StartWindow) {
	m_pUi->setupUi(this);
	QDesktopWidget *desktop = QApplication::desktop();

	updateDisplayNames();

	cout << "Window on display: " << desktop->screenNumber(this) << endl;
}

StartWindow::~StartWindow() {
	delete m_pUi;
	m_pUi = nullptr;
}

void StartWindow::updateDisplayNames() {
	QDesktopWidget *desktop = QApplication::desktop();

	m_displayNames.clear();

	const int currentControlDisplay = m_pUi->selectControlDisplay->currentIndex();
	const int currentPresentationDisplay = m_pUi->selectPresentationDisplay->currentIndex();

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

	if (-1 < currentControlDisplay && currentControlDisplay < (int) m_displayNames.size())
		m_pUi->selectControlDisplay->setCurrentIndex(currentControlDisplay);
	else
		m_pUi->selectControlDisplay->setCurrentIndex(desktop->screenNumber(this));

	if (-1 < currentPresentationDisplay && currentPresentationDisplay < (int) m_displayNames.size())
		m_pUi->selectPresentationDisplay->setCurrentIndex(currentPresentationDisplay);
	else
		m_pUi->selectPresentationDisplay->setCurrentIndex(0);
}

void StartWindow::on_actionOpen_File_triggered() {
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
			tr("PDF Documents (*.pdf)"));
	std::cout << "Chosen file: " << fileName.toStdString() << std::endl;

	Poppler::Document *doc = Poppler::Document::load(fileName);

	if (nullptr == doc) {
		std::cout << "Document not loaded" << std::endl;
	} else {
		std::cout << "Document loaded" << std::endl;
		Poppler::Page *page = doc->page(0);

		QSize size = page->pageSize();
		QImage renderedPDF = page->renderToImage(physicalDpiX() * 2,
				physicalDpiY() * 2, size.width(), size.height());
		delete page;
		page = nullptr;
//
//
//		ui->pdfLabel->setPixmap(QPixmap::fromImage(renderedPDF));
	}

//	showFullScreen();
}

} /* namespace qSlides */
