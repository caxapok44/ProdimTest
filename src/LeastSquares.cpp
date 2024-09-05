#include "LeastSquares.hpp"

#include <cmath>
#include <iostream>

LeastSquares::LeastSquares(const std::vector<Point>& points):
	m_points(points), m_numberOfPoints(points.size()), m_sumX(0), m_sumY(0), m_sumX2(0), m_sumY2(0), m_sumXY(0), m_sumX2Y(0),
	m_sumXY2(0), m_sumX3(0), m_sumY3(0), m_a_M(0), m_b_M(0), m_radius(0)
{
	for (const auto& p : points)
	{
		double xi = p.x;
		double yi = p.y;
		double xi2 = xi * xi;
		double yi2 = yi * yi;

		m_sumX += xi;
		m_sumY += yi;
		m_sumX2 += xi2;
		m_sumY2 += yi2;
		m_sumXY += xi * yi;
		m_sumX2Y += xi2 * yi;
		m_sumXY2 += yi2 * xi;
		m_sumX3 += xi * xi2;
		m_sumY3 += yi * yi2;
	}
	if (calculateCenterAndRadius())
	{
		m_isAbleToBuild = true;
	}

}

bool LeastSquares::isAbleToBuild() const
{
	return m_isAbleToBuild;
}


double LeastSquares::a_point() const
{
	return m_a_M;
}

double LeastSquares::b_point() const
{
	return m_b_M;
}

double LeastSquares::radius() const
{
	return m_radius;
}


bool LeastSquares::calculateCenterAndRadius()
{
	double A = m_numberOfPoints * m_sumX2 - m_sumX * m_sumX;
	double B = m_numberOfPoints * m_sumXY - m_sumX * m_sumY;
	double C = m_numberOfPoints * m_sumY2 - m_sumY * m_sumY;
	double D = 0.5 * ((m_numberOfPoints * m_sumXY2) - (m_sumX * m_sumY2) + (m_numberOfPoints * m_sumX3) - (m_sumX * m_sumX2));
	double E = 0.5 * ((m_numberOfPoints * m_sumX2Y) - (m_sumY * m_sumX2) + (m_numberOfPoints * m_sumY3) - (m_sumY * m_sumY2));

	double denom = A * C - B * B;
	if (denom == 0)
	{
		std::cerr << "Denominator is zero; cannot fit a unique circle." << std::endl;
		return false;
	}

	m_a_M = (D * C - B * E) / denom;
	m_b_M = (A * E - B * D) / denom;

	// Calculate the radius of the circle
	m_radius = 0;
	for (const auto& p : m_points)
	{
		m_radius += std::sqrt(std::pow(p.x - m_a_M, 2) + std::pow(p.y - m_b_M, 2));
	}
	m_radius /= m_numberOfPoints;

	return true;
}