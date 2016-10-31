#pragma once
#include "Space2D.h"
 

class Box2D :public Space2D
{
public:
	Box2D(float x, float y, float x1, float y1);
	Box2D();
	Box2D(float x, float y);
	void correctness();

	double getLength();// ���������� �����
	double getWidth();//���������� ������

	void move(float dx, float dy);//���������� ������� �� ���������

	void setLcorner(float x, float y);//�������� ���������� ������ ����
	void setRcorner(float x, float y);//�������� ���������� ������� ����

	float getLcornerX();// ���������� ���������� � ������ ����
	float getLcornerY();// ���������� ���������� � ������ ����
	float getRcornerX();// ���������� ���������� � ������� ����
	float getRcornerY();// ���������� ���������� � ������� ����
	float getCenterX();// ���������� ���������� � ������
	float getCenterY();// ���������� ���������� � ������

	void address(); //������� �� ����� �����

	
	bool intersection(Box2D & obj);//�������� �� �����������
	bool include(Box2D & pol); //���������

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

