#include "Vec2D.h"
#include <cmath>

Vec2D::Vec2D(float x_in, float y_in)
	:
	x(x_in),
	y(y_in)
{
}

Vec2D Vec2D::operator+(const Vec2D& rhs) const
{
	return Vec2D(x + rhs.x, y + rhs.y);
}

Vec2D& Vec2D::operator+=(const Vec2D& rhs)
{
	return *this = *this + rhs;
}

Vec2D Vec2D::operator*(int rhs) const
{
	return Vec2D(x * rhs, y * rhs);
}

Vec2D& Vec2D::operator*=(int rhs)
{
	return *this = *this * rhs;
}

Vec2D Vec2D::operator-(const Vec2D& rhs) const
{
	return Vec2D(x - rhs.x, y - rhs.y);
}

Vec2D& Vec2D::operator-=(const Vec2D& rhs)
{
	return *this = *this - rhs;
}

Vec2D Vec2D::operator/(int rhs) const
{
	return Vec2D(x / rhs, y / rhs);
}

Vec2D& Vec2D::operator/=(int rhs)
{
	return *this = *this / rhs;
}

float Vec2D::GetLength() const
{
	return std::sqrt(float(GetLengthSq()));
}

int Vec2D::GetLengthSq() const
{
	return x * x + y * y;
}
