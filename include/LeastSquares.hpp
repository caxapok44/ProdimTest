#ifndef LEASTSQUARES_HPP
#define LEASTSQUARES_HPP

#include <cmath>
#include <iostream>
#include <vector>

#include "Point.hpp"

class LeastSquares
{
public:
	LeastSquares(const std::vector<Point>& points);

	bool calculateCenterAndRadius();

	bool isAbleToBuild() const;

	double radius() const;
	double a_point() const;
	double b_point() const;

private:
	int m_numberOfPoints;
	bool m_isAbleToBuild = false;
	double m_sumX, m_sumY;
	double m_sumX2, m_sumY2, m_sumXY;
	double m_sumX2Y, m_sumXY2, m_sumX3, m_sumY3;
	double m_a_M, m_b_M;
	double m_radius;
	std::vector<Point> m_points;
};

#endif	// LEASTSQUARES_HPP