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

#ifndef PDFMODEL_H_
#define PDFMODEL_H_

#include "IDocumentModel.h"

//#include <memory>
//using std::shared_ptr;

#include "poppler-qt4.h"

namespace qSlides {

class PdfModel: public qSlides::IDocumentModel {
public:
	PdfModel(const QString & filePath);
	virtual ~PdfModel();

	QImage	renderPage(const int nPageNumber, const int nWidth, const int nHeight);

private:
	Poppler::Document *m_pDocument;
};

} /* namespace qSlides */
#endif /* PDFMODEL_H_ */
