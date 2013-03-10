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

#include "IDocumentModel.h"

#include <memory>
using std::make_shared;

#include <stdexcept>
using std::runtime_error;

#include <QString>
#include <QFileInfo>

namespace qSlides {

IDocumentModel::IDocumentModel(const QString & filePath) {
	m_pStrAbsolutFilePath = make_shared<QString>(filePath);

	if (*m_pStrAbsolutFilePath == "")
		throw eDocumentEmptyFileNameException();

	QFileInfo fileInfo(*m_pStrAbsolutFilePath);

	if (!fileInfo.exists())
		throw eDocumentFileNotExistsException();

	if (!fileInfo.isReadable())
		throw eDocumentFileNotReadable();

	m_pStrFileName = make_shared<QString>(fileInfo.fileName());
}

IDocumentModel::~IDocumentModel() {

}

shared_ptr<QString> IDocumentModel::getAbsoluteFileName() {
	return m_pStrAbsolutFilePath;
}

shared_ptr<QString> IDocumentModel::getFileName() {
	return m_pStrFileName;
}

} /* namespace qSlides */
