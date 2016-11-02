#include "Figures.h"

Box2D::Box2D(float x, float y, float x1, float y1) 
{	
	m_lCorner = Point2D(x, y);
	m_rCorner = Point2D(x1, y1);
	Correctness();
}
Box2D::Box2D() = default;
Box2D::Box2D(float x, float y) 
{
	m_lCorner=Point2D(0.0f, 0.0f);
	m_rCorner = Point2D(x, y);
	Correctness();
};
void Box2D::Correctness()  
{
	if (m_lCorner.GetX() == m_rCorner.GetX())
	{
		m_rCorner.AddX(1);
	}
	if (m_lCorner.GetY() == m_rCorner.GetY())
	{
		m_rCorner.AddY(1);
	}
	if (m_lCorner.GetX() > m_rCorner.GetX())
	{
		float a = m_lCorner.GetX();
		m_lCorner.SetX(m_rCorner.GetX());
		m_rCorner.SetX(a);
	}
	if (m_lCorner.GetY() > m_rCorner.GetY())
	{
		float a = m_lCorner.GetY();
		m_lCorner.SetY(m_rCorner.GetY());
		m_rCorner.SetY(a);
	}

}

double Box2D::GetLength() const
{
	return (m_rCorner.GetX() - m_lCorner.GetX());
};
double Box2D::GetWidth() const
{
	return (m_rCorner.GetX() - m_lCorner.GetX());
};

void Box2D::Move(float dx, float dy)
{
	m_lCorner.AddX(dx);
	m_lCorner.AddY(dy);
	m_rCorner.AddX(dx);
	m_rCorner.AddY(dy);
}

void Box2D::SetLcorner(float x, float y)
{
	m_lCorner = { x, y };
	void correctness();
}
void Box2D::SetRcorner(float x, float y)
{
	m_rCorner = { x, y };
	void correctness();
}

float Box2D::GetLcornerX() const
{
	return m_lCorner.GetX();
}
float Box2D::GetLcornerY() const
{
	return m_lCorner.GetY();
}
float Box2D::GetRcornerX() const
{
	return m_rCorner.GetX();
}
float Box2D::GetRcornerY() const
{
	return m_rCorner.GetY();
}
float Box2D::GetCenterX() const
{
	return (m_rCorner.GetX()-m_lCorner.GetX())/2;
}
float Box2D::GetCenterY() const
{
	return (m_rCorner.GetY() - m_lCorner.GetY()) / 2;
}




bool Box2D::Intersection(Box2D const & box) const
{
  if (m_rCorner.GetX() < box.GetLcornerX()) return false;
  if (m_lCorner.GetX() > box.GetRcornerX()) return false; 
  if (m_rCorner.GetY() < box.GetLcornerY()) return false;
  if (m_lCorner.GetY() > box.GetRcornerY()) return false;
    return true;  
};


///////////////////////////////////////////ЛУЧ

Ray2D::Ray2D(float x0, float y0, float x, float y) :m_origin(x0, y0), m_direction(x , y ) {};
Ray2D::Ray2D() = default;
Ray2D::Ray2D(float x, float y) :m_origin(0.0f, 0.0f), m_direction(x , y ) {};
 
float Ray2D::GetOriginX() const
{
	return m_origin.GetX();
}
float Ray2D::GetOriginY() const
{
	return m_origin.GetY();
}

float Ray2D::GetDirectionX() const
{
	return m_direction.GetX();
}
float Ray2D::GetDirectionY() const
{
	return m_direction.GetY();
}
float Ray2D::GetK() const
{
	
	return m_k;
}


bool Ray2D::Intersection(Box2D const & b) const
{
	if (GetDirectionX() > 0)
	{
		if (b.GetRcornerX() <GetOriginX())
			return false;
	}
	if (GetDirectionX() < 0)
	{
		if (b.GetLcornerX() > GetOriginX())
			return false;
	}

	if (GetDirectionY() > 0)
	{
		if (b.GetRcornerY() < GetOriginY())
			return false;
	}
	if (GetDirectionY() < 0)
	{
		if (b.GetLcornerY() > GetOriginY())
			return false;
	}

	if (GetDirectionX() == 0)
	{
		if (belong(b.GetLcornerX(), GetOriginX(), b.GetRcornerY()))
		{
			if (GetDirectionY() > 0)
				if (b.GetRcornerY() >= GetOriginY())
					return true;
			if (GetDirectionY() < 0)
				if (b.GetLcornerY() <= GetOriginY())
					return true;
		}
	}
	if (GetDirectionY() == 0)
	{
		if (belong(b.GetLcornerY(), GetOriginY(), b.GetRcornerY()))
		{
			if (GetDirectionX() > 0)
				if (b.GetRcornerX() >= GetOriginX())
					return true;
			if (GetDirectionX() < 0)
				if (b.GetLcornerX() <= GetOriginX())
					return true;
		}
	}

	float x0, y0, x1, y1;
	y0 = (b.GetLcornerX() - GetOriginX()) * GetK()+GetOriginY();
	y1 = (b.GetRcornerX() - GetOriginX()) * GetK()+GetOriginY();
	x0 = (b.GetLcornerY() - GetOriginY()) / GetK()+GetOriginX();
	x1 = (b.GetRcornerY() - GetOriginY()) / GetK()+GetOriginX();
	return belong(b.GetLcornerX(), x0, b.GetRcornerX()) || belong(b.GetLcornerY(), y0, b.GetRcornerY())
		|| belong(b.GetLcornerX(), x1, b.GetRcornerX()) || belong(b.GetLcornerY(), y1, b.GetRcornerY());
}
