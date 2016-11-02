#pragma once
#include "Point2D.h"
 

class Box2D 
{
public:
	Box2D(float x, float y, float x1, float y1);
	Box2D();
	Box2D(float x, float y);
	void Correctness();

	double GetLength() const;// ���������� �����
	double GetWidth() const;//���������� ������

	void Move(float dx, float dy);//���������� ������� �� ���������

	void SetLcorner(float x, float y);//�������� ���������� ������ ����
	void SetRcorner(float x, float y);//�������� ���������� ������� ����

	float GetLcornerX() const;// ���������� ���������� � ������ ����
	float GetLcornerY() const;// ���������� ���������� � ������ ����
	float GetRcornerX() const;// ���������� ���������� � ������� ����
	float GetRcornerY() const;// ���������� ���������� � ������� ����
	float GetCenterX() const;// ���������� ���������� � ������
	float GetCenterY() const;// ���������� ���������� � ������

	

	
	bool Intersection(Box2D const & obj) const;//�������� �� �����������


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

