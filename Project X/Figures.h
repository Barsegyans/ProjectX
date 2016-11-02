#pragma once
#include "Point2D.h"
 

class Box2D 
{
public:
	Box2D(float x, float y, float x1, float y1);
	Box2D();
	Box2D(float x, float y);
	void Correctness();

	double GetLength() const;// возвращает длину
	double GetWidth() const;//возвращает ширину

	void Move(float dx, float dy);//переещение объекта на плоскости

	void SetLcorner(float x, float y);//изменить координаты левого угла
	void SetRcorner(float x, float y);//изменить координаты правого угла

	float GetLcornerX() const;// возвращает координату х левого угла
	float GetLcornerY() const;// возвращает координату у левого угла
	float GetRcornerX() const;// возвращает координату х правого угла
	float GetRcornerY() const;// возвращает координату у правого угла
	float GetCenterX() const;// возвращает координату х центра
	float GetCenterY() const;// возвращает координату у центра

	

	
	bool Intersection(Box2D const & obj) const;//проверка на пересечение


private:
	Point2D m_lCorner, m_rCorner;

};

class Ray2D 
{
public:

	Ray2D(float x0, float y0, float x, float y) ;
	Ray2D();
	Ray2D(float x, float y);

	float GetOriginX() const;
	float GetOriginY()const;
		  
	float GetDirectionX() const;
	float GetDirectionY() const;
	float GetK() const;

	
	bool Intersection(Box2D const & obj) const;
private:
	Point2D m_origin, m_direction;
	float m_k = (m_direction.GetY()) / (m_direction.GetX());
};

