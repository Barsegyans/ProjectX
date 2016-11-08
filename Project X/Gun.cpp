#include"Gun.h"


Gun::Gun(float x, float y, float x1, float y1) : Box2D(x, y, x1, y1) {};
Gun::Gun(Box2D const &  body):Box2D(body) {};



