#include"gtest/gtest.h"
#include"Figures.h"
#include<conio.h>
#include "Point2D.h"

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
}
TEST(ray_test, box_test)
{
  Ray2D ray1(0, 0, 1, 1);
  Ray2D ray2( 2, 2);
  Ray2D ray3(-1, -1, 0, 0);

  EXPECT_EQ(ray1.GetDirectionX(), 1);
  EXPECT_EQ(ray2.GetDirectionY(), 2);
  EXPECT_EQ(ray3.GetOriginX(), -1);
  EXPECT_EQ(ray2.GetOriginY(), 0);
	
  EXPECT_EQ(ray1.GetK(), 1);
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
