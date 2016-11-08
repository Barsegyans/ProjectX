#pragma once
#include "Figures.h"
#include"Bullet.h"

class Obstacle : public Box2D
{
public:
  Obstacle() = default;
  Obstacle(Box2D const &  body);
  Obstacle(Point2D const &  a,Point2D const &  b);
  Obstacle(float x, float y, float x1, float y1);

  void Hit(Bullet const & b);
  float GetHealth() const;

  ~Obstacle() = default;
private:
  float m_health = 1000;
};

 