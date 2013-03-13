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

#ifndef PRESENTATIONCONTROLLER_H_
#define PRESENTATIONCONTROLLER_H_

#include "IDocumentModel.h"

#include <memory>
using std::shared_ptr;

namespace qSlides {

class PresentationController {
public:
	PresentationController(shared_ptr<IDocumentModel> pDocumentModel, const int nControlDisplay, const int nPresentationDisplay);
	virtual ~PresentationController();

	void startPresentation();

protected:
	shared_ptr<IDocumentModel> m_pDocumentModel;
	int m_nControlDisplayNumber;
	int m_nPresentationDisplay;
};

} /* namespace qSlides */
#endif /* PRESENTATIONCONTROLLER_H_ */
