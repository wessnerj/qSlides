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

#include "PdfModel.h"

#include <QDebug>
#include <QSize>

#include <memory>
using std::unique_ptr;

namespace qSlides {

PdfModel::PdfModel(const QString & filePath) : IDocumentModel(filePath) {
	m_pDocument = Poppler::Document::load(*m_pStrAbsolutFilePath);

	if (nullptr == m_pDocument || m_pDocument->isLocked())
		throw eDocumentLoadException();

	// Set render to SplashBackend
	m_pDocument->setRenderBackend(Poppler::Document::RenderBackend::SplashBackend);

	// Set some render hints
	m_pDocument->setRenderHint(Poppler::Document::RenderHint::Antialiasing);
	m_pDocument->setRenderHint(Poppler::Document::RenderHint::TextAntialiasing);
}

PdfModel::~PdfModel() {
	if (nullptr != m_pDocument)
		delete m_pDocument;
	m_pDocument = nullptr;
}

QImage PdfModel::renderPage(const int nPageNumber, const int nWidth, const int nHeight) {
	unique_ptr<Poppler::Page> pPage(m_pDocument->page(nPageNumber)); // Document starts at page 0
	if (nullptr == pPage)
		throw eDocumentPageNotFoundException();

	const QSize pageSize = pPage->pageSize();
	const int nPageWidth = pageSize.width();	// Unit is points (1/72 inch)!
	const int nPageHeight = pageSize.height();	// Unit is points (1/72 inch)!

	// Calculate the output image size
	int nImageHeight = nHeight; // normally defined by the y resolution
	int nImageWidth = (nImageHeight * nPageWidth) / nPageHeight;

	if (nImageWidth > nWidth) {
		// defined by x resolution
		nImageWidth = nWidth;
		nImageHeight = (nImageWidth * nPageHeight) / nPageWidth;
	}

	// Calculate the x/y-resolutions for rendering
	const int xres = (nImageWidth * 72) / nPageWidth;
	const int yres = (nImageHeight * 72) / nPageHeight;

	qDebug() << "page> Width: " << QString::number(pageSize.width()) << " height: " << QString::number(pageSize.height());

	QImage renderedImage = pPage->renderToImage(xres, yres, 0, 0, nImageWidth, nImageHeight);

	return renderedImage;
}

} /* namespace qSlides */
