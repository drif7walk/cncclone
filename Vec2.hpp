#ifndef VEC2_HPP
#define VEC2_HPP

#include <SDL2/SDL.h>

class Vec2 {

public:

	double X;
	double Y;

	Vec2() { this->X = 0; this->Y = 0; }
	Vec2(double v) { this->X = v; this->Y = v; }
	Vec2(double x, double y) { this->X = x; this->Y = y; }

	/* Operator overloads */
	Vec2*& operator=(const Vec2*& other)
	{
		this->X = other->X;
		this->Y = other->Y;
	}

	Vec2*& operator+(const Vec2*& other)
	{
		this->X += other->X;
		this->Y += other->Y;
	}

	Vec2*& operator+(const double val)
	{
		this->X += val;
		this->Y += val;
	}

	Vec2*& operator*(const double val)
	{
		this->X *= val;
		this->Y *= val;
	}

	

	~Vec2();

};

#endif
