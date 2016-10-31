#pragma once
#include<iostream>
#include<math.h>
#include<ctime>
#include <string> 
float const kEps = 1e-5;
float const pi = 3.14159265358979323846;
bool belong(float a, float b, float c);

bool EqualWithEps(float v1, float v2);

class Space2D
{
public:

	Space2D(float x, float y) :m_x(x), m_y(y) {};
	Space2D() = default;
	Space2D(Space2D const & obj): m_x(obj.m_x), m_y(obj.m_y) {}; // конструктор копирования

	void setX(float x);
	
	void setY(float y);
	float getX();
	float getY();
	void addX(float x);
	void addY(float y);


	bool operator == (Space2D const & obj) const;
	Space2D & operator = (Space2D const & obj);

	~Space2D();

private:
	
	float m_x = 0.0f, m_y = 0.0f;

};
