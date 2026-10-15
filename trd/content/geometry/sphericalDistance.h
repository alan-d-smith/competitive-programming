/**
 * Author: Ulf Lundstrom
 * Date: 2009-04-07
 * License: CC0
 * Source: My geometric reasoning
 * Description: Returns the shortest (great-circle) distance between two points on a sphere
 * with radius radius. f1, f2 are longitudes ($\phi$, from the x axis) and t1, t2 are angles
 * from the north pole ($\theta$, from the z axis), all in radians.
 * For latitude $\ell$, use $\theta = \pi/2 - \ell$. For cartesian points on the unit
 * sphere, set dx, dy, dz to their difference.
 * Status: tested on kattis:airlinehub
 */
#pragma once

double sphericalDistance(double f1, double t1,
		double f2, double t2, double radius) {
	double dx = sin(t2)*cos(f2) - sin(t1)*cos(f1);
	double dy = sin(t2)*sin(f2) - sin(t1)*sin(f1);
	double dz = cos(t2) - cos(t1);
	double d = sqrt(dx*dx + dy*dy + dz*dz);
	return radius*2*asin(d/2);
}
