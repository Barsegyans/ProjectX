#include <iostream>
#include"Figures.h"
#include <conio.h>


int main()
{
	Box2D box1(0, 0, 1, 1);
	Box2D box2(-1, -1, 2, 2);
	Box2D box3(-1, -1, 0, 0);

	Ray2D ray1(0, 0, 1, 1);
	Ray2D ray2(3, 3, 1, 1);

	if (box2.include(box1))
		std::cout << "box2 include box1" << std::endl;
	if (box1.include(box2))
		std::cout << "box1 include box2" << std::endl;
	if (box2.include(box3))
		std::cout << "box2 include box3" << std::endl;
	if (box3.include(box2))
		std::cout << "box3 include box2" << std::endl;

	if (box1.intersection(box2))
		std::cout << "box1 intersect with box2" << std::endl;
	if (box1.intersection(box3))
		std::cout << "box1 intersect with box3" << std::endl;
	if (box2.intersection(box3))
		std::cout << "box2 intersect with box3" << std::endl;

	if (box2.intersection(box1))
		std::cout << "box2 intersect with box1" << std::endl;
	if (box3.intersection(box1))
		std::cout << "box3 intersect with box1" << std::endl;
	if (box3.intersection(box2))
		std::cout << "box3 intersect with box2" << std::endl;


	if (ray1.intersection(box1))
		std::cout << "ray1 intersetc with box 1" << ::std::endl;
	if (ray1.intersection(box2))
		std::cout << "ray1 intersetc with box 2" << ::std::endl;
	if (ray1.intersection(box3))
		std::cout << "ray1 intersetc with box 3" << ::std::endl;

	if (ray2.intersection(box1))
		std::cout << "ray2 intersetc with box 1" << ::std::endl;
	if (ray2.intersection(box2))
		std::cout << "ray2 intersetc with box 2" << ::std::endl;
	if (ray2.intersection(box3))
		std::cout << "ray2 intersetc with box 3" << ::std::endl;


	_getch();
	return 0;
}