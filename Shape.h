#ifndef _SHAPE_H
#define _SHAPE_H

#include <string>
#include "Point.h"

class Visitor;
class Circle;
class Rectangle;
class Line;

/// @brief Abstract shape class.

class Shape
{
private:
	/// @brief The coordinates of the shape.
	Point location;
	/// @brief The shape type.
	std::string type;
	/// @brief The color fill of the shape.
	std::string fill;

protected:
	/// @brief Constructor used by the derrived classes
	Shape(const double _x, const double _y, const std::string& _type, const std::string& _fill);

public:
	/// @brief Applies modifications to this object with the help of a visitor object.
	virtual void accept(Visitor*) = 0;
	/// @brief Checks if the current object is inside of another shape object.
	virtual bool isInside(Shape*) = 0;
	/// @brief Checks if the current object contains a circle object.
	virtual bool contains(Circle&);
	/// @brief Checks if the current object contains a rectangle object.
	virtual bool contains(Rectangle&);
	/// @brief Checks if the current object contains a line object.
	virtual bool contains(Line&);

	const double getX() const;
	const double getY() const;
	const std::string& getType() const;
	const std::string& getFill() const;
	const Point& getLocation() const;

	void setX(const double _x);
	void setY(const double _y);

	/// @brief Deletes all data from this class and its derived classes.
	virtual ~Shape();
};

#endif