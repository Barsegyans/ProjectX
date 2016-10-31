#include"gtest/gtest.h"
#include"Figures.h"
#include<conio.h>
#include "Space2D.h"




TEST(Space2d_test, test_construction)
{
	// Тест на создание объекта по умолчанию.
	Space2D p1;
	EXPECT_EQ(p1.getX(), 0.0f);
	EXPECT_EQ(p1.getY(), 0.0f);

	// Тест на создание объекта с параметрами.
	Space2D p2 = { 1.2f, 2.4f };
	EXPECT_EQ(p2.getX(), 1.2f);
	EXPECT_EQ(p2.getY(), 2.4f);

	// Тест на создание копии объекта.
	Space2D p3 = p2;
	EXPECT_EQ(p3, p2);
}

TEST(Space2d_test, test_initializer_list)
{
	Space2D p1 = { 1.0f, 2.0f};
	EXPECT_EQ(p1.getX(), 1.0f);
	EXPECT_EQ(p1.getY(), 2.0f);

}

TEST(Space2d_test, test_assignment)
{
	Space2D p1;
	p1 = { 1.2f, 2.4f };
	EXPECT_EQ(p1, Space2D(1.2f, 2.4f));
 
}





TEST(box_test, box_test)
{
	Box2D box1(0, 0, 1, 1);
	Box2D box2(-1, -1, 2, 2);
	Box2D box3(-1, -1, 0, 0);

	EXPECT_EQ(box1.getLength(), 1);
	EXPECT_EQ(box1.getLcornerX(), 0);
	EXPECT_EQ(box1.getRcornerY(), 1);

	box1.move(1, 1);
	EXPECT_EQ(box1.getLcornerY(), 1);
	EXPECT_EQ(box1.getRcornerX(), 2);

	box1.setLcorner(0, 0);
	box1.setRcorner(1, 1);
	EXPECT_EQ(box1.getLcornerX(), 0);
	EXPECT_EQ(box1.getRcornerY(), 1);


	EXPECT_EQ(box1.intersection(box2), false);
	EXPECT_EQ(box1.intersection(box3), true);
	EXPECT_EQ(box1.intersection(box1), true);
	EXPECT_EQ(box2.intersection(box2), true);
	EXPECT_EQ(box2.intersection(box3), true);
	EXPECT_EQ(box2.intersection(box1), false);
	EXPECT_EQ(box3.intersection(box1), true);
	EXPECT_EQ(box3.intersection(box2), true);
	EXPECT_EQ(box3.intersection(box3), true);

	EXPECT_EQ(box1.include(box2), false);
	EXPECT_EQ(box1.include(box3), false);
	EXPECT_EQ(box1.include(box1), false);
	EXPECT_EQ(box2.include(box2), false);
	EXPECT_EQ(box2.include(box3), false);
	EXPECT_EQ(box2.include(box1), true);
	EXPECT_EQ(box3.include(box1), false);
	EXPECT_EQ(box3.include(box2), false);
	EXPECT_EQ(box3.include(box3), false);


}
TEST(ray_test, box_test)
{
	Ray2D ray1(0, 0, 1, 1);
	Ray2D ray2( 2, 2);
	Ray2D ray3(-1, -1, 0, 0);

	EXPECT_EQ(ray1.getDirectionX(), 1);
	EXPECT_EQ(ray2.getDirectionY(), 2);
	EXPECT_EQ(ray3.getOriginX(), -1);
	EXPECT_EQ(ray2.getOriginY(), 0);
	
	EXPECT_EQ(ray1.getK(), 1);

}
TEST(rayBox_test, ray_and_box_intersection)
{
	Ray2D ray1(1, 1);
	Ray2D ray2(3, 3, 1, 1);
	Ray2D ray3(3, 3, -1, -1);

	Box2D box1(0, 0, 1, 1);
	Box2D box2(-2, -2, 1, 1);
	Box2D box3(5, 5, 7, 7);


	EXPECT_EQ(ray1.intersection(box1), true);
	EXPECT_EQ(ray1.intersection(box2), true);
	EXPECT_EQ(ray1.intersection(box3), true);
	EXPECT_EQ(ray2.intersection(box1), false);
	EXPECT_EQ(ray2.intersection(box2), false);
	EXPECT_EQ(ray2.intersection(box3), true);
	EXPECT_EQ(ray3.intersection(box1), true);
	EXPECT_EQ(ray3.intersection(box2), true);
	EXPECT_EQ(ray3.intersection(box3), false);

	
}
TEST(pause, pause)
{
	system("pause");
}