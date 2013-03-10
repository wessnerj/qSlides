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

namespace qSlides {

class eDocumentLoadException { };
class eDocumentEmptyFileNameException : public eDocumentLoadException { };
class eDocumentFileNotExistsException : public eDocumentLoadException { };
class eDocumentFileNotReadable : public eDocumentLoadException { };

class IDocumentModel {
public:
	IDocumentModel(const QString & filePath);
	virtual ~IDocumentModel();

	shared_ptr<QString> getAbsoluteFileName();
	shared_ptr<QString> getFileName();

protected:
	shared_ptr<QString> m_pStrAbsolutFilePath;
	shared_ptr<QString> m_pStrFileName;
};

} /* namespace qSlides */
#endif /* IDOCUMENTMODEL_H_ */
