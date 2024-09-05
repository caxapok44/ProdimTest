#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#include "LeastSquares.hpp"
#include "Point.hpp"

std::vector<Point> readPoints(const std::string& filename);

void displayResults(double a_M, double b_M, double r_M);

int main()
{
	std::string filename = "points.txt";
	std::vector<Point> points = readPoints(filename);

	if (points.size() < 3)
	{
		std::cerr << "Need at least 3 points to fit a circle." << std::endl;
		return -1;
	}

	LeastSquares leastSquares(points);

	if (!leastSquares.isAbleToBuild())
	{
		return -1;
	}

	displayResults(leastSquares.a_point(), leastSquares.b_point(), leastSquares.radius());

	return 0;
}

std::vector<Point> readPoints(const std::string& filename)
{
	std::vector<Point> points;
	std::ifstream infile(filename);

	if (!infile)
	{
		std::cerr << "Unable to open file " << filename << std::endl;
		return points;
	}

	double x, y;
	while (infile >> x >> y)
	{
		points.push_back({x, y});
	}

	return points;
}

void displayResults(double a_M, double b_M, double r_M)
{
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Center of the circle: (" << a_M << ", " << b_M << ")" << std::endl;
	std::cout << "Radius of the circle: " << r_M << std::endl;
}
