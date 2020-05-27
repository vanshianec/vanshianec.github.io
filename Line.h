#ifndef _LINE_H
#define _LINE_H

#include "Shape.h"


/// @brief Line shape class.

class Line : public Shape
{
private:
	/// @brief The end point of the line.
	Point endLocation;

public:
	/// @brief Constructor used to create a line object.
	Line(const double _x, const double _y, const std::string& _type,
		const std::string& _fill, const double _xEnd, const double _yEnd);
	/// @brief Applies modifications to this line object with the help of a visitor object.
	void accept(Visitor*);
	/// @brief Checks if the current line object is inside of another shape object.
	bool isInside(Shape*);

	const double getXEnd() const;
	const double getYEnd() const;
	const Point& getEndLocation() const;

	void setXEnd(const double _xEnd);
	void setYEnd(const double _yEnd);
};

#endif