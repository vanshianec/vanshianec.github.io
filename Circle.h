#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape.h"

/// @brief Circle shape class.

class Circle : public Shape
{
private:
	/// @brief The radius of the circle.
	double radius;
public:
	/// @brief Constructor used to create a circle object.
	Circle(const double _x, const double _y, const std::string& _type,
		const std::string& _fill, double _radius);
	/// @brief Applies modifications to this circle object with the help of a visitor object.
	void accept(Visitor*);
	/// @brief Checks if the circle object is inside a shape object.
	bool isInside(Shape*);
	/// @brief Checks if the circle object contains a circle object.
	bool contains(Circle&);
	/// @brief Checks if the circle object contains a rectangle object.
	bool contains(Rectangle&);
	/// @brief Checks if the circle object contains a line object.
	bool contains(Line&);

	const double getRadius() const;
};

#endif