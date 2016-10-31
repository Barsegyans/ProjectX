#include "Figures.h"

Box2D::Box2D(float x, float y, float x1, float y1) 
{
	
	m_Lcorner = Space2D(x, y);
	m_Rcorner = Space2D(x1, y1);
	void correctness();
	m_center = Space2D((x1 - x) / 2, (y1 - y) / 2);
	
}
Box2D::Box2D() = default;
Box2D::Box2D(float x, float y) 
{
	m_Lcorner=Space2D(0.0f, 0.0f);
	m_Rcorner = Space2D(x, y);
	void correctness();
	m_center = Space2D(x/2, y/2);
	
};
void Box2D::correctness()
{
	while (m_Lcorner.getX() == m_Rcorner.getX())
	{
		std::cout << "enter another X for corner" << std::endl;
		float a;
		std::cin >> a;
		m_Rcorner.setX(a);
	}
	while (m_Lcorner.getY() == m_Rcorner.getY())
	{
		std::cout << "enter another Y for corner" << std::endl;
		float a;
		std::cin >> a;
		m_Rcorner.setY(a);
	}
	while (m_Lcorner.getX() > m_Rcorner.getX())
	{
		float a = m_Lcorner.getX();
		m_Lcorner.setX(m_Rcorner.getX());
		m_Rcorner.setX(a);
	}
	while (m_Lcorner.getY() > m_Rcorner.getY())
	{
		float a = m_Lcorner.getY();
		m_Lcorner.setY(m_Rcorner.getY());
		m_Rcorner.setY(a);
	}

}

double Box2D::getLength()
{
	return (m_Rcorner.getX() - m_Lcorner.getX());
};
double Box2D::getWidth()
{
	return (m_Rcorner.getX() - m_Lcorner.getX());
};

void Box2D::move(float dx, float dy)
{
	m_Lcorner.addX(dx);
	m_Lcorner.addY(dy);
	m_Rcorner.addX(dx);
	m_Rcorner.addY(dy);
}

void Box2D::setLcorner(float x, float y)
{
	m_Lcorner = { x, y };
	void correctness();
}
void Box2D::setRcorner(float x, float y)
{
	m_Rcorner = { x, y };
	void correctness();
}

float Box2D::getLcornerX()
{
	return m_Lcorner.getX();
}
float Box2D::getLcornerY()
{
	return m_Lcorner.getY();
}
float Box2D::getRcornerX()
{
	return m_Rcorner.getX();
}
float Box2D::getRcornerY()
{
	return m_Rcorner.getY();
}
float Box2D::getCenterX()
{
	return m_center.getX();
}
float Box2D::getCenterY()
{
	return m_center.getY();
}

void  Box2D::address()
{
	std::cout << "Left corner " << " {" << getLcornerX() << ", " << getLcornerY() << "}     ";
	std::cout << "Right corner" << " {" << getRcornerX() << ", " << getRcornerY() << "}" << std::endl;

}


bool Box2D::intersection(Box2D & obj)
{
	Space2D *corner1 = new Space2D[4];// ¬ершины первого пр€моугольника
	corner1[0] = Space2D(getLcornerX(), getLcornerY());
	corner1[1] = Space2D(getLcornerX(), getRcornerY());
	corner1[2] = Space2D(getRcornerX(), getRcornerY());
	corner1[3] = Space2D(getRcornerX(), getLcornerY());
	Space2D *corner2 = new Space2D[4];// ¬ершины второго пр€моугольника
	corner2[0] = Space2D(obj.getLcornerX(), obj.getLcornerY());
	corner2[1] = Space2D(obj.getLcornerX(), obj.getRcornerY());
	corner2[2] = Space2D(obj.getRcornerX(), obj.getRcornerY());
	corner2[3] = Space2D(obj.getRcornerX(), obj.getLcornerY());

	for (int i = 0; i < 4; i++)
	{
		int t = i + 1;
		if (t == 4)
			t = 0;
		for (int j = 0; j < 4; j++)
		{
			int r = j + 1;
			if (r == 4)
				r = 0;
			float v1 = (corner1[t].getX() - corner1[i].getX())*(corner2[j].getY() - corner1[i].getY()) -
				(corner1[t].getY() - corner1[i].getY())*(corner2[j].getX() - corner1[i].getX());
			float v2 = (corner1[t].getX() - corner1[i].getX())*(corner2[r].getY() - corner1[i].getY()) -
				(corner1[t].getY() - corner1[i].getY())*(corner2[r].getX() - corner1[i].getX());
			if (((v1 > 0) && (v2 < 0)) || ((v1 < 0) && v2>0)) //если векторные произведени€ разных знаков, значит вершины лежат по разные стороны от отрезка
			{                                                // требуетс€ обратна€ проверка
				float b1 = (corner2[r].getX() - corner2[j].getX())*(corner1[i].getY() - corner2[j].getY()) -
					(corner2[r].getY() - corner2[j].getY())*(corner1[i].getX() - corner2[j].getX());
				float b2 = (corner2[r].getX() - corner2[j].getX())*(corner1[t].getY() - corner2[j].getY()) -
					(corner2[r].getY() - corner2[j].getY())*(corner1[t].getX() - corner2[j].getX());
				if (((b1 > 0) && (b2 < 0)) || ((b1 < 0) && b2>0))
				{
					delete[] corner1;
					delete[] corner2;
					return true;
				}
			}
			if (EqualWithEps(v1, 0))//если  векторное прозведение 0 смотрим принадлежит ли 
			{
				if (belong(corner1[t].getX(), corner2[j].getX(), corner1[i].getX()) && belong(corner1[t].getY(), corner2[j].getY(), corner1[i].getY()))
					return true;
			}
			if (EqualWithEps(v2, 0))//если  векторное прозведение 0 смотрим принадлежит ли 
			{
				if (belong(corner1[t].getX(), corner2[r].getX(), corner1[i].getX()) && belong(corner1[t].getY(), corner2[r].getY(), corner1[i].getY()))
					return true;
			}
		}
		
	}

	delete[] corner1;
	delete[] corner2;
	return false;
};

bool Box2D::include(Box2D & obj) //включение
{
	if (intersection(obj))// провер€ем пересечение(если оно есть, значит ни о каком включении речи идти не может)
		return false;
	Space2D *corner1 = new Space2D[4];// ¬ершины первого пр€моугольника
	corner1[0] = Space2D(getLcornerX(), getLcornerY());
	corner1[1] = Space2D(getLcornerX(), getRcornerY());
	corner1[2] = Space2D(getRcornerX(), getRcornerY());
	corner1[3] = Space2D(getRcornerX(), getLcornerY());
	Space2D *corner2 = new Space2D[4];// ¬ершины второго пр€моугольника
	corner2[0] = Space2D(obj.getLcornerX(), obj.getLcornerY());
	corner2[1] = Space2D(obj.getLcornerX(), obj.getRcornerY());
	corner2[2] = Space2D(obj.getRcornerX(), obj.getRcornerY());
	corner2[3] = Space2D(obj.getRcornerX(), obj.getLcornerY());

	
	for (int k = 0; k < 4; k++) // провер€ем включение вершин obj в исследуемый пр€моугольник
	{
		
		for (int i = 0; i < 4; i++)
		{
			int t = i + 1;
			if (t == 4)
				t = 0;

			float v1 = (corner2[k].getX() - corner1[i].getX())*(corner1[t].getY() - corner1[i].getY())
				- (corner2[k].getY() - corner1[i].getY())*(corner1[t].getX() - corner1[i].getX());
			float v2 = ((corner2[k].getX() - corner1[t].getX())*(m_center.getY() - corner1[t].getY()))
				- (corner2[k].getY() - corner1[t].getY())*(m_center.getX() - corner1[t].getX());
			float v3 = ((corner2[k].getX() - m_center.getX())*(corner1[i].getY() - m_center.getY()))
				- (corner2[k].getY() - m_center.getY())*(corner1[i].getX() - m_center.getX());
			if (((v1 > 0) && (v2 > 0) && (v3 > 0)) || ((v1 < 0) && (v2 < 0) && (v3 < 0)))// если хоть одна вершина принадлежит,
			{                                                                            //значит принадлжит и весь пр€моуг(т.к нет пересечени€)
				delete[] corner1;
				delete[] corner2;
				return true;
			}
		}
	}
	delete[] corner1;
	delete[] corner2;
	return false;
	}

///////////////////////////////////////////Ћ”„

Ray2D::Ray2D(float x0, float y0, float x, float y) :m_origin(x0, y0), m_direction(x , y ) {};
Ray2D::Ray2D() = default;
Ray2D::Ray2D(float x, float y) :m_origin(0.0f, 0.0f), m_direction(x , y ) {};
 
float Ray2D::getOriginX()
{
	return m_origin.getX();
}
float Ray2D::getOriginY()
{
	return m_origin.getY();
}

float Ray2D::getDirectionX()
{
	return m_direction.getX();
}
float Ray2D::getDirectionY()
{
	return m_direction.getY();
}
float Ray2D::getK()
{
	updateK();
	return m_k;
}
void  Ray2D::updateK()
{
	m_k = (m_direction.getY()) / (m_direction.getX());
}


bool Ray2D::intersection(Box2D & b)
{
	if (getDirectionX() > 0)
	{
		if (b.getRcornerX() <getOriginX())
			return false;
	}
	if (getDirectionX() < 0)
	{
		if (b.getLcornerX() > getOriginX())
			return false;
	}

	if (getDirectionY() > 0)
	{
		if (b.getRcornerY() < getOriginY())
			return false;
	}
	if (getDirectionY() < 0)
	{
		if (b.getLcornerY() > getOriginY())
			return false;
	}

	if (getDirectionX() == 0)
	{
		if (belong(b.getLcornerX(), getOriginX(), b.getRcornerY()))
		{
			if (getDirectionY() > 0)
				if (b.getRcornerY() >= getOriginY())
					return true;
			if (getDirectionY() < 0)
				if (b.getLcornerY() <= getOriginY())
					return true;
		}
	}
	if (getDirectionY() == 0)
	{
		if (belong(b.getLcornerY(), getOriginY(), b.getRcornerY()))
		{
			if (getDirectionX() > 0)
				if (b.getRcornerX() >= getOriginX())
					return true;
			if (getDirectionX() < 0)
				if (b.getLcornerX() <= getOriginX())
					return true;
		}
	}

	float x0, y0, x1, y1;
	y0 = (b.getLcornerX() - getOriginX()) * getK()+getOriginY();
	y1 = (b.getRcornerX() - getOriginX()) * getK()+getOriginY();
	x0 = (b.getLcornerY() - getOriginY()) / getK()+getOriginX();
	x1 = (b.getRcornerY() - getOriginY()) / getK()+getOriginX();
	return belong(b.getLcornerX(), x0, b.getRcornerX()) || belong(b.getLcornerY(), y0, b.getRcornerY())
		|| belong(b.getLcornerX(), x1, b.getRcornerX()) || belong(b.getLcornerY(), y1, b.getRcornerY());
}
