#pragma once

class Vec2D
{
public:
	Vec2D() = default;
	Vec2D(float x_in, float y_in);
	Vec2D operator+(const Vec2D& rhs) const;
	Vec2D& operator+=(const Vec2D& rhs);
	Vec2D operator*(int rhs) const;
	Vec2D& operator*=(int rhs);
	Vec2D operator-(const Vec2D& rhs) const;
	Vec2D& operator-=(const Vec2D& rhs);
	Vec2D operator/(int rhs) const;
	Vec2D& operator/=(int rhs);
	float GetLength() const;
	int GetLengthSq() const;
public:
	float x;
	float y;
};