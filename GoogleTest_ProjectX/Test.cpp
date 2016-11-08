﻿#include"gtest/gtest.h"
#include"Figures.h"
#include<conio.h>
#include "Point2D.h"
#include"Alien.h"
#include"Bullet.h"
#include"Gun.h"
#include"Obstacle.h"
#include"Space.h"

TEST(Point2D_test, test_construction)
{
  // Тест на создание объекта по умолчанию.
  Point2D p1;
  EXPECT_EQ(p1.GetX(), 0.0f);
  EXPECT_EQ(p1.GetY(), 0.0f);
  // Тест на создание объекта с параметрами.
  Point2D p2 = { 1.2f, 2.4f };
  EXPECT_EQ(p2.GetX(), 1.2f);
  EXPECT_EQ(p2.GetY(), 2.4f);
  // Тест на создание копии объекта.
  Point2D p3 = p2;
  EXPECT_EQ(p3, p2);
}

TEST(Point2D_test, test_initializer_list)
{
  Point2D p1 = { 1.0f, 2.0f};
  EXPECT_EQ(p1.GetX(), 1.0f);
  EXPECT_EQ(p1.GetY(), 2.0f);
}

TEST(Point2D_test, test_assignment)
{
  Point2D p1;
  p1 = { 1.2f, 2.4f };
  EXPECT_EQ(p1, Point2D(1.2f, 2.4f));
}

TEST(box_test, box_test)
{
  Box2D box1(0, 0, 1, 1);
  Box2D box2(-1, -1, 2, 2);
  Box2D box3(-1, -1, 0, 0);
	Box2D box4(Point2D(1,0), Point2D (2,1));

  EXPECT_EQ(box1.GetHeight(), 1);
  EXPECT_EQ(box1.GetLCorner().GetX(), 0);
  EXPECT_EQ(box1.GetRCorner().GetY(), 1);

  box1.Move(1, 1);
  EXPECT_EQ(box1.GetLCorner().GetY(), 1);
  EXPECT_EQ(box1.GetRCorner().GetX(), 2);

  box1.SetLcorner(0, 0);
  box1.SetRcorner(1, 1);
  EXPECT_EQ(box1.GetLCorner().GetX(), 0);
  EXPECT_EQ(box1.GetRCorner().GetY(), 1);

  EXPECT_EQ(box1.Intersection(box2), true);
  EXPECT_EQ(box1.Intersection(box3), true);
  EXPECT_EQ(box1.Intersection(box1), true);
  EXPECT_EQ(box2.Intersection(box2), true);
  EXPECT_EQ(box2.Intersection(box3), true);
  EXPECT_EQ(box2.Intersection(box1), true);
  EXPECT_EQ(box3.Intersection(box1), true);
  EXPECT_EQ(box3.Intersection(box2), true);
  EXPECT_EQ(box3.Intersection(box3), true);

  EXPECT_EQ(box4.GetLCorner().GetY(), 0);
  EXPECT_EQ(box4.GetLCorner().GetX(), 1);
  EXPECT_EQ(box4.GetRCorner().GetY(), 1);
  EXPECT_EQ(box4.GetRCorner().GetX(), 2);
}
TEST(ray_test, box_test)
{
  Ray2D ray1(0, 0, 1, 1);
  Ray2D ray2( 2, 2);
  Ray2D ray3(-1, -1, 0, 0);
  Ray2D ray4(Point2D(0,0),Point2D(1,1));

  EXPECT_EQ(ray4.GetDirection().GetX(), 1);
  EXPECT_EQ(ray4.GetDirection().GetY(), 1);
  EXPECT_EQ(ray4.GetOrigin().GetX(), 0);
  EXPECT_EQ(ray4.GetOrigin().GetY(), 0);

  EXPECT_EQ(ray1.GetDirection().GetX(), 1);
  EXPECT_EQ(ray2.GetDirection().GetY(), 2);
  EXPECT_EQ(ray3.GetOrigin().GetX(), -1);
  EXPECT_EQ(ray2.GetOrigin().GetY(), 0);
	
  EXPECT_EQ(ray1.GetK(), 1);
  ray1=ray2;
  EXPECT_EQ(ray1.GetDirection().GetX(), 2);
  EXPECT_EQ(ray1.GetOrigin().GetY(), 0);
}
TEST(rayBox_test, ray_and_box_intersection)
{
  Ray2D ray1(1, 1);
  Ray2D ray2(3, 3, 1, 1);
  Ray2D ray3(3, 3, -1, -1);

  Box2D box1(0, 0, 1, 1);
  Box2D box2(-2, -2, 1, 1);
  Box2D box3(5, 5, 7, 7);

  EXPECT_EQ(ray1.Intersection(box1), true);
  EXPECT_EQ(ray1.Intersection(box2), true);
  EXPECT_EQ(ray1.Intersection(box3), true);
  EXPECT_EQ(ray2.Intersection(box1), false);
  EXPECT_EQ(ray2.Intersection(box2), false);
  EXPECT_EQ(ray2.Intersection(box3), true);
  EXPECT_EQ(ray3.Intersection(box1), true);
  EXPECT_EQ(ray3.Intersection(box2), true);
  EXPECT_EQ(ray3.Intersection(box3), false);
 }

//.....................................................................



TEST(Alien_test, test_construction)
{
  Box2D box(0,0,1,1);
  Alien a1(1,1,2,2);
  Alien a2(box);
  Alien a3(Box2D(Point2D(2,2), Point2D(3, 3)));
 
  EXPECT_EQ(a1.GetLCorner(),Point2D(1,1));
  EXPECT_EQ(a1.GetRCorner(), Point2D(2, 2));
											 
  EXPECT_EQ(a2.GetLCorner(), Point2D(0, 0));
  EXPECT_EQ(a2.GetRCorner(), Point2D(1, 1));
												 
  EXPECT_EQ(a3.GetLCorner(), Point2D(2, 2));
  EXPECT_EQ(a3.GetRCorner(), Point2D(3, 3));
}

TEST(Gun_test, test_construction)
{
  Box2D box(0, 0, 1, 1);
  Gun g1(1, 1, 2, 2);
  Gun g2(box);
  Gun g3(Box2D(Point2D(2, 2), Point2D(3, 3)));

  EXPECT_EQ(g1.GetLCorner(), Point2D(1, 1));
  EXPECT_EQ(g1.GetRCorner(), Point2D(2, 2));
  									 
  EXPECT_EQ(g2.GetLCorner(), Point2D(0, 0));
  EXPECT_EQ(g2.GetRCorner(), Point2D(1, 1));
											 
  EXPECT_EQ(g3.GetLCorner(), Point2D(2, 2));
  EXPECT_EQ(g3.GetRCorner(), Point2D(3, 3));
}
TEST(Bullet_test, test_construction)
{
  Ray2D ray(1,1,1,0);
  Box2D box(1,1,2,2);

  Bullet b1(1,1,2,2,0,1);
  Bullet b2(box,ray.GetDirection());

  EXPECT_EQ(b1.GetLCorner(), Point2D(1, 1));
  EXPECT_EQ(b1.GetRCorner(), Point2D(2, 2));

  EXPECT_EQ(b2.GetLCorner(), Point2D(1, 1));
  EXPECT_EQ(b2.GetRCorner(), Point2D(2, 2));

  EXPECT_EQ(b1.GetDirection(), Point2D(0, 1));
  EXPECT_EQ(b2.GetDirection(), Point2D(1, 0));

  EXPECT_EQ(b1.GetOrigin(), Point2D(1.5f, 1.5f));
  EXPECT_EQ(b2.GetOrigin(), Point2D(1.5f, 1.5f));

  EXPECT_EQ(b1.GetDamage(), 100);
  EXPECT_EQ(b2.GetSpeed(), 1);
}
TEST(Obstacle_test, test_construction)
{
  Box2D box(0, 0, 1, 1);
  Obstacle o1 (1, 1, 2, 2);
  Obstacle o2 (box);
  Obstacle o3 (Box2D(Point2D(2, 2), Point2D(3, 3)));
						
  EXPECT_EQ(o1.GetLCorner(), Point2D(1, 1));
  EXPECT_EQ(o1.GetRCorner(), Point2D(2, 2));
					
  EXPECT_EQ(o2.GetLCorner(), Point2D(0, 0));
  EXPECT_EQ(o2.GetRCorner(), Point2D(1, 1));
						
  EXPECT_EQ(o3.GetLCorner(), Point2D(2, 2));
  EXPECT_EQ(o3.GetRCorner(), Point2D(3, 3));

  Bullet b(-1,-1,0,0,1,1);
  o2.Hit(b);
  EXPECT_EQ(o2.GetHealth(), 900);
}

TEST(Space_test, test_construction)
{
  Box2D box(0, 0, 1, 1);
  Space s1(1, 1);
  Space s2(box);
  Space s3(Point2D(2, 2), Point2D(3, 3));
 
  EXPECT_EQ(s1.GetLCorner(), Point2D(0, 0));
  EXPECT_EQ(s1.GetRCorner(), Point2D(1, 1));
						
  EXPECT_EQ(s2.GetLCorner(), Point2D(0, 0));
  EXPECT_EQ(s2.GetRCorner(), Point2D(1, 1));
						
  EXPECT_EQ(s3.GetLCorner(), Point2D(2, 2));
  EXPECT_EQ(s3.GetRCorner(), Point2D(3, 3));
}
