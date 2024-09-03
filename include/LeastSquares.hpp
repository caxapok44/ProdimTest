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

	bool calculateCenterAndRadius(double& a_M, double& b_M, double& r_M) const;

private:
	int m_numberOfPoints;
	double m_sumX, m_sumY;
	double m_sumX2, m_sumY2, m_sumXY;
	double m_sumX2Y, m_sumXY2, m_sumX3, m_sumY3;
	std::vector<Point> m_points;
};

#endif	// LEASTSQUARES_HPP