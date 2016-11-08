#pragma once
#include"Figures.h"


class Alien : public Box2D
{
public:
	Alien() = default;
  Alien(float x, float y, float x1, float y1);
	Alien(Box2D const & body);

	

	~Alien() = default;
private:
	float m_speed;
	float rate = 1; //скорострельность пуль/сек
	float m_health = 100;
};
