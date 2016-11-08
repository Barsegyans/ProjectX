#pragma once
#include"Figures.h"
#include<ctime>
#include"Space.h"

class Space;
class Bullet : public Box2D, public Ray2D
{
public:
  Bullet()=default;
	Bullet(Box2D const & b,Point2D const & dir);
	Bullet(float x, float y, float x1, float y1,float x2,float y2);
	Bullet(Point2D const &  lCorner,Point2D const &  rCorner,Point2D const & direction);
  float GetDamage() const;
	float GetSpeed() const;
 

	~Bullet() = default;
private:
	float const  m_standartHeigth=1, m_standartWidth=1;
  float m_timeOfShot=clock();
  float const m_speed=1;//единиц в секунду
  float const m_damage=100;
};
