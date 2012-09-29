/*
 JWildfireC - an external C-based fractal-flame-renderer for JWildfire
 Copyright (C) 2012 Andreas Maschke

 This is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser
 General Public License as published by the Free Software Foundation; either version 2.1 of the
 License, or (at your option) any later version.
 
 This software is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License along with this software;
 if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 02110-1301 USA, or see the FSF site: http://www.fsf.org.
 */
#ifndef JWFVAR_UNPOLAR_H_
#define JWFVAR_UNPOLAR_H_

#include "jwf_Constants.h"
#include "jwf_Variation.h"

class UnpolarFunc: public Variation {
public:
	UnpolarFunc() {
	}

	const char* getName() const {
		return "unpolar";
	}

	void transform(FlameTransformationContext *pContext, XForm *pXForm, XYZPoint *pAffineTP, XYZPoint *pVarTP, JWF_FLOAT pAmount) {
		float r = JWF_EXP(pAffineTP->y);
		float s = JWF_SIN(pAffineTP->x);
		float c = JWF_COS(pAffineTP->x);
		pVarTP->y += vvar_2 * r * c;
		pVarTP->x += vvar_2 * r * s;
		if (pContext->isPreserveZCoordinate) {
			pVarTP->z += pAmount * pAffineTP->z;
		}
	}

	UnpolarFunc* makeCopy() {
		return new UnpolarFunc(*this);
	}

	void init(FlameTransformationContext *pContext, XForm *pXForm, JWF_FLOAT pAmount) {
		vvar = pAmount / M_PI;
		vvar_2 = vvar * 0.5f;
	}

private:
	float vvar, vvar_2;

};

#endif // JWFVAR_UNPOLAR_H_