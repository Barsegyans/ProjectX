#pragma once
#include "Point2D.h"
 

class Box2D 
{
public:
  Box2D(float x, float y, float x1, float y1);
  Box2D()=default;
  Box2D(float x, float y);
  void Correctness();
  double GetHeight() const;// возвращает длину
  double GetWidth() const;//возвращает ширину
  void Move(float dx, float dy);//переещение объекта на плоскости

  void SetLcorner(float x, float y);//изменить координаты левого угла
  void SetRcorner(float x, float y);//изменить координаты правого угла

  Point2D GetLCorner() const;
  Point2D GetRCorner() const;
  Point2D GetCenter() const;
	
  bool Intersection(Box2D const & obj) const;//проверка на пересечение

  ~Box2D()=default;
private:
  Point2D m_lCorner, m_rCorner;

};

class Ray2D 
{
public:
  Ray2D(float x0, float y0, float x, float y) ;
  Ray2D()=default;
  Ray2D(float x, float y);
  float GetOriginX() const;
  float GetOriginY()const;	  
  float GetDirectionX() const;
  float GetDirectionY() const;
  float GetK() const;
  bool Intersection(Box2D const & obj) const;
  ~Ray2D() = default;
private:
  Point2D m_origin, m_direction;
  float m_k = (m_direction.GetY()) / (m_direction.GetX());
};

