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

#ifndef IDOCUMENTMODEL_H_
#define IDOCUMENTMODEL_H_

#include <memory>
using std::shared_ptr;

#include <QString>
#include <QFileInfo>
#include <QImage>

namespace qSlides {

/**
 * General exception if the file could not be load
 */
class eDocumentLoadException { };
/**
 * Exception if the filename was empty
 */
class eDocumentEmptyFileNameException : public eDocumentLoadException { };
/**
 * Exception if filename leads to non-existing file
 */
class eDocumentFileNotExistsException : public eDocumentLoadException { };
/**
 * Exception if file was not readable
 */
class eDocumentFileNotReadableException : public eDocumentLoadException { };

/**
 * Exception for calling a invalid page number
 */
class eDocumentPageNotFoundException { };

/**
 * Interface for document model
 */
class IDocumentModel {
public:
	IDocumentModel(const QString &filePath);
	virtual ~IDocumentModel();

	/**
	 * Getter for absolute file path
	 * @return
	 */
	shared_ptr<QString> getAbsoluteFileName();
	/**
	 * Getter for filename
	 * @return
	 */
	shared_ptr<QString> getFileName();

	/**
	 * Renders the given page to QImage. The page is scaled to fit the height and width argument without distorting.
	 *
	 * @param nPageNumber	number of page to render
	 * @param nWidth		width of the resulting QImage
	 * @param nHeight		height of the resulting QImage
	 * @return				QImage with the desired page
	 */
	virtual QImage		renderPage(const int nPageNumber, const int nWidth, const int nHeight) = 0;

protected:
	/**
	 * Absolute filepath of the document
	 */
	shared_ptr<QString> m_pStrAbsolutFilePath;

	/**
	 * Filename of document
	 */
	shared_ptr<QString> m_pStrFileName;
};

} /* namespace qSlides */
#endif /* IDOCUMENTMODEL_H_ */
