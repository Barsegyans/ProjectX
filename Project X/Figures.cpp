#include "Figures.h"

Box2D::Box2D(float x, float y, float x1, float y1) 
{	
  m_lCorner = Point2D(x, y);
  m_rCorner = Point2D(x1, y1);
  Correctness();
}
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

double Box2D::GetHeight() const
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

Point2D Box2D::GetLCorner() const
{
  return m_lCorner;
}
Point2D Box2D::GetRCorner() const
{
  return m_rCorner;
}
Point2D Box2D::GetCenter() const
{
  return Point2D((GetRCorner().GetX()- GetLCorner().GetX())/2, (GetRCorner().GetY() - GetLCorner().GetY()) / 2);
}


bool Box2D::Intersection(Box2D const & box) const
{
  if (m_rCorner.GetX() < box.GetLCorner().GetX()) return false;
  if (m_lCorner.GetX() > box.GetRCorner().GetX()) return false;
  if (m_rCorner.GetY() < box.GetLCorner().GetY()) return false;
  if (m_lCorner.GetY() > box.GetRCorner().GetY()) return false;
    return true; 
  box.GetLCorner().GetX();
};


///////////////////////////////////////////ЛУЧ

Ray2D::Ray2D(float x0, float y0, float x, float y) :m_origin(x0, y0), m_direction(x , y ) {};

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
    if (b.GetRCorner().GetX() <GetOriginX())
      return false;
  }
  if (GetDirectionX() < 0)
  {
    if (b.GetLCorner().GetX() > GetOriginX())
      return false;
  }
  if (GetDirectionY() > 0)
  {
    if (b.GetRCorner().GetY() < GetOriginY())
      return false;
  }
  if (GetDirectionY() < 0)
  {
    if (b.GetLCorner().GetY() > GetOriginY())
      return false;
  }

  if (GetDirectionX() == 0)
  {
    if (belong(b.GetLCorner().GetX(), GetOriginX(), b.GetRCorner().GetY()))
      {
        if (GetDirectionY() > 0)
          if (b.GetRCorner().GetY() >= GetOriginY())
            return true;
          if (GetDirectionY() < 0)
            if (b.GetLCorner().GetY() <= GetOriginY())
              return true;
      }
  }
  if (GetDirectionY() == 0)
  {
    if (belong(b.GetLCorner().GetY(), GetOriginY(), b.GetRCorner().GetY()))
    {
      if (GetDirectionX() > 0)
        if (b.GetRCorner().GetX() >= GetOriginX())
          return true;
      if (GetDirectionX() < 0)
	if (b.GetLCorner().GetX() <= GetOriginX())
          return true;
  }
  }

  float x0, y0, x1, y1;
  y0 = (b.GetLCorner().GetX() - GetOriginX()) * GetK()+GetOriginY();
  y1 = (b.GetRCorner().GetX() - GetOriginX()) * GetK()+GetOriginY();
  x0 = (b.GetLCorner().GetY() - GetOriginY()) / GetK()+GetOriginX();
  x1 = (b.GetRCorner().GetY() - GetOriginY()) / GetK()+GetOriginX();
  return belong(b.GetLCorner().GetX(), x0, b.GetRCorner().GetX()) || belong(b.GetLCorner().GetY(), y0, b.GetRCorner().GetY())
    || belong(b.GetLCorner().GetX(), x1, b.GetRCorner().GetX()) || belong(b.GetLCorner().GetY(), y1, b.GetRCorner().GetY());
}
