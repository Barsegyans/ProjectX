#include"Bullet.h"

Bullet::Bullet(float x, float y, float x1, float y1, float x2, float y2) : Box2D(x, y, x1, y1), Ray2D((x1 + x) / 2, (y1 + y) / 2, x2, y2) {};

Bullet::Bullet(Box2D const & b, Point2D const & dir): Box2D(b), Ray2D(b.GetCenter(),dir) {};


Bullet::Bullet(Point2D  const & lCorner, Point2D const &  rCorner, Point2D  const & direction):
     Box2D(lCorner, rCorner), Ray2D(Point2D((rCorner.GetX() + lCorner.GetX()) / 2, (rCorner.GetY() + lCorner.GetY()) / 2), direction) {};


float Bullet::GetSpeed() const
{
  return m_speed;
}

float Bullet::GetDamage() const
{
  return m_damage;
}