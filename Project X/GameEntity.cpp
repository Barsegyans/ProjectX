#include"GameEntity.h"


GameEntity::GameEntity(Box2D body, float health):m_body(body),m_health(health) {};
GameEntity::GameEntity(Box2D body, Ray2D dir,float damage):m_body(body),m_direction(dir),m_health(1),m_damage(damage) {};

Box2D GameEntity::GetBody() const &
{
  return m_body;
}
Ray2D GameEntity::GetRay() const &
{
  return m_direction;
}
float GameEntity::GetHealth() const
{
  return m_health;
}
void GameEntity::SetHealth(float a) 
{
  m_health+=a;
}
float GameEntity::GetDamage() const
{
  return m_damage;
}
bool GameEntity::Hit(GameEntity & g)
{
  if (m_body.Intersection(g.GetBody()))
  {
     m_health -= g.GetDamage();
     g.SetHealth(-m_damage);
  return true;
  }
  return false;
}