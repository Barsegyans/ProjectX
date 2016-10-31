#pragma once
#include "Space2D.h"
 

class Box2D :public Space2D
{
public:
	Box2D(float x, float y, float x1, float y1);
	Box2D();
	Box2D(float x, float y);
	void correctness();

	double getLength();// возвращает длину
	double getWidth();//возвращает ширину

	void move(float dx, float dy);//переещение объекта на плоскости

	void setLcorner(float x, float y);//изменить координаты левого угла
	void setRcorner(float x, float y);//изменить координаты правого угла

	float getLcornerX();// возвращает координату х левого угла
	float getLcornerY();// возвращает координату у левого угла
	float getRcornerX();// возвращает координату х правого угла
	float getRcornerY();// возвращает координату у правого угла
	float getCenterX();// возвращает координату х центра
	float getCenterY();// возвращает координату у центра

	void address(); //выводит на экран адрес

	
	bool intersection(Box2D & obj);//проверка на пересечение
	bool include(Box2D & pol); //включение

private:
	Space2D m_Lcorner, m_Rcorner,m_center;

};

class Ray2D :public Space2D
{
public:

	Ray2D(float x0, float y0, float x, float y) ;
	Ray2D();
	Ray2D(float x, float y);

	float getOriginX();
	float getOriginY();

	float getDirectionX();
	float getDirectionY();
	float getK();
	void updateK();

	
	bool intersection(Box2D & obj);
private:
	Space2D m_origin, m_direction;
	float m_k = 0.0f;
};

