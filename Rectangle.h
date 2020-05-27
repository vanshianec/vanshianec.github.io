#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Shape.h"

/// @brief Rectangle shape class.

class Rectangle : public Shape
{
private:
	/// @brief The height of the rectangle.
	double height;
	/// @brief The width of the rectangle.
	double width;

public:
	/// @brief Constructor used to create a rectangle object.
	Rectangle(const double _x, const double _y, const std::string& _type,
		const std::string& _fill, const double _width, const double _height);
	/// @brief Applies modifications to this rectangle object with the help of a visitor object.
	void accept(Visitor*);
	/// @brief Checks if the rectangle object is inside of another shape object.
	bool isInside(Shape*);
	/// @brief Checks if the rectangle object contains a circle object.
	bool contains(Circle&);
	/// @brief Checks if the rectangle object contains a rectangle object.
	bool contains(Rectangle&);
	/// @brief Checks if the rectangle object contains a line object.
	bool contains(Line&);

	const double getHeight() const;
	const double getWidth() const;

};

#endif