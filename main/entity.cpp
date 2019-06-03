#include "entity.hpp"

Entity::Entity(byte basePositionX, byte basePositionY, byte life, byte strength)
{
  _baseX = basePositionX;
  _baseY = basePositionY;
  _x = basePositionX;
  _y = basePositionY;

  _life = life;
  _strength = strength;
  _state = idle;

  _anim = 0;
  _movementAnim = 0;

  _sprite = 0;
}

byte Entity::X()
{
  return _x;
}

byte Entity::Y()
{
  return _y;
}

byte Entity::Life()
{
  return _life;
}

byte Entity::Anim()
{
  return _anim;
}

byte Entity::MovementAnim()
{
  return _movementAnim;
}

bool Entity::Sprite()
{
  return _anim >= ANIMATION_FRAME_DURATION/2;
}

void Entity::TakeDamage(byte damage)
{
  _life -= damage;
}

void Entity::Update()
{
  // Sprite anim
  _anim = ++_anim;
  if (_anim >= ANIMATION_FRAME_DURATION)
    _anim = 0;
};