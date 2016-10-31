#include "Space2D.h"

bool belong(float a, float b, float c)
{
	return  ((((b >= a)) && (b <= c))
		|| ((b >= c) && (b <= a)));

}
bool EqualWithEps(float v1, float v2)
{
	return fabs(v1 - v2) < kEps;
}


void Space2D:: setX(float x)
{
	m_x = x;
};
void Space2D::setY(float y)
{
	m_y = y;
};

float Space2D::getX()
{
	return m_x;
}
float  Space2D::getY()
{
	return m_y;
}
void Space2D::Space2D::addX(float x)
{
	m_x += x;
};
void Space2D::addY(float y)
{
	m_y += y;
};


bool  Space2D::operator == (Space2D const & obj) const
{
	return EqualWithEps(m_x, obj.m_x) && EqualWithEps(m_y, obj.m_y);
}
Space2D &  Space2D::operator = (Space2D const & obj)
{
	if (this == &obj) return *this;
	m_x = obj.m_x;
	m_y = obj.m_y;
	return *this;
}

Space2D::~Space2D() = default;