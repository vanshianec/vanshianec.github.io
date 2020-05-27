#ifndef _POINT_H
#define _POINT_H

/// @brief Point class.

class Point
{
private:
	//@brief X coordinate
	double x;
	//@brief Y coordinate
	double y;
public:
	Point(double _x, double _y);

	const double getX() const;
	const double getY() const;

	void setX(const double _x);
	void setY(const double _y);

	//@brieft Calculates distance between two points
	const double distance(const Point& other);
};

#endif