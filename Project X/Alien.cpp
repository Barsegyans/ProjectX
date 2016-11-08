#include"Alien.h"


Alien::Alien(float x, float y, float x1, float y1) : Box2D(x, y, x1, y1) {};
Alien::Alien(Box2D const &  body): Box2D(body) {};


