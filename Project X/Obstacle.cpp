#include"Obstacle.h"



Obstacle::Obstacle(Box2D  const & body):Box2D(body) {};
Obstacle::Obstacle(Point2D const &  a, Point2D const &  b) :Box2D(a, b) {};
Obstacle::Obstacle(float x, float y, float x1, float y1) :Box2D(x, y, x1, y1) {};

void Obstacle::Hit(Bullet  const & b)
{
if(Intersection(b))
  m_health-=b.GetDamage();
}
float Obstacle::GetHealth() const
{
  return m_health;
}