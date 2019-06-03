#include "enemy.h"

Enemy::Enemy(byte basePositionX, byte basePositionY)
{
  _baseX = basePositionX;
  _baseY = basePositionY;
  _x = basePositionX;
  _y = basePositionY;
  _life = 100;
  _anim = 0;
  _sprite = 0;
  _state = 0;
}

byte Enemy::X()
{
  return _x;
}

byte Enemy::Y()
{
  return _y;
}

byte Enemy::Life()
{
  return _life;
}

bool Enemy::Sprite()
{
  return _anim >= 30;
}

void Enemy::UpdateSprite()
{
  _anim = ++_anim;
  if (_anim >= 60)
    _anim = 0;
};

void Enemy::UpdateState(byte state)
{
  _state = state;
  if (state == 1)
  {
    _x = _x + 10;
    _state = 0;
  }
};

void Enemy::TakeDamage(byte damage){
  _life = 0;
}