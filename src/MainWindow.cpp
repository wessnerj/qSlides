/*
 * MainWindow.cpp
 *
 *  Created on: Mar 5, 2013
 *      Author: hdr
 */

#include "MainWindow.h"
#include "ui_mainWindow.h"

#include <iostream>
using std::cout;
using std::endl;

#include "poppler-qt4.h"

#include <QFileDialog>
#include <QDesktopWidget>

namespace qSlides {

MainWindow::MainWindow(QWidget *parent) :
		QMainWindow(parent), m_pUi(new Ui::MainWindow) {
	m_pUi->setupUi(this);
	QDesktopWidget *desktop = QApplication::desktop();

	const int nScreenCount = desktop->screenCount();

	cout << "Number of desktops: " << nScreenCount << endl;
	for (int i = 0; i < nScreenCount; i++) {
		QRect oRect = desktop->screenGeometry(i);

		cout << "Display " << i << ": " << oRect.width() << "x" << oRect.height() << endl;
	}

	cout << "Window on display: " << desktop->screenNumber(this) << endl;
}

MainWindow::~MainWindow() {
	delete m_pUi;
	m_pUi = nullptr;
}

void MainWindow::updateDisplayNames() {
	QDesktopWidget *desktop = QApplication::desktop();

	delete desktop;
}

void MainWindow::on_actionOpen_File_triggered() {
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
		QImage renderedPDF = page->renderToImage(physicalDpiX()*2, physicalDpiY()*2, size.width(), size.height());
		delete page;
		page = nullptr;
//
//
//		ui->pdfLabel->setPixmap(QPixmap::fromImage(renderedPDF));
	}

//	showFullScreen();
}

} /* namespace qSlides */
