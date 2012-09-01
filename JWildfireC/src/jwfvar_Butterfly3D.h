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

#ifndef JWFVAR_BUTTERFLY3D_H_
#define JWFVAR_BUTTERFLY3D_H_

#include "jwf_Constants.h"
#include "jwf_Variation.h"

class Butterfly3DFunc: public Variation {
public:
	Butterfly3DFunc() {
	}

	const char* getName() const {
		return "butterfly3D";
	}

	void transform(FlameTransformationContext *pContext, XYZPoint *pAffineTP, XYZPoint *pVarTP, float pAmount) {
    float wx = pAmount * 1.3029400317411197908970256609023f;

    float y2 = pAffineTP->y * 2.0;
    float r = wx * sqrtf(fabs(pAffineTP->y * pAffineTP->x) / (EPSILON + pAffineTP->x * pAffineTP->x + y2 * y2));

    pVarTP->x += r * pAffineTP->x;
    pVarTP->y += r * y2;
    pVarTP->z += r * fabs(y2) * sqrt(pAffineTP->x * pAffineTP->x + pAffineTP->y * pAffineTP->y) / 4.0;
	}

	Butterfly3DFunc* makeCopy() {
		return new Butterfly3DFunc(*this);
	}

};

#endif // JWFVAR_BUTTERFLY_H_
