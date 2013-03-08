/*
 * MainWindow.cpp
 *
 *  Created on: Mar 5, 2013
 *      Author: hdr
 */

#include "MainWindow.h"
#include "ui_mainWindow.h"

#include <iostream>
#include "poppler-qt4.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
		QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
}

MainWindow::~MainWindow() {
	delete ui;
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

		physicalDpiX();

		Poppler::Page *page = doc->page(0);
		QImage renderedPDF = page->renderToImage(physicalDpiX(),
				physicalDpiX());
		delete page;
		page = nullptr;
	}

	showFullScreen();
}
