/**
 * Author: Ulf Lundstrom
 * Date: 2009-03-21
 * License: CC0
 * Source:
 * Description: Which side of the line through s and e the point p is on, looking from s towards e:
 * 1 = left, 0 = on the line, -1 = right. It is the basic test behind most geometry:
 * a and b are on the same side iff sideOf(s, e, a) == sideOf(s, e, b); walking a $\to$ b $\to$ c turns left
 * iff sideOf(a, b, c) == 1; two segments cross iff each one's ends are on opposite sides of the other's
 * line; p is inside a convex polygon iff it is on the same side of every edge.
 * It multiplies coordinates, so int overflows beyond about $10^4$: use Point<ll> (fine up to about $10^9$).
 * With doubles, pass eps: points within distance eps of the line count as on it. A good default is
 * $10^{-9}$ for coordinates up to about $10^6$.
 * Usage: P s(0, 0), e(1, 0); // the x-axis, looking right
 * sideOf(s, e, P(5, 2)); // 1: (5, 2) is on the left
 * sideOf(s, e, p, 1e-9); // P = Point<double>, with eps
 * Status: tested
 */
#pragma once

#include "Point.h"

template<class P>
int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

template<class P>
int sideOf(P s, P e, P p, double eps) {
	auto a = (e-s).cross(p-s);
	double l = (e-s).dist()*eps;
	return (a > l) - (a < -l);
}
