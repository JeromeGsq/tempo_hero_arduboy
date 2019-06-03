#include "timber.h"
#include "gameManager.h"

Timber::Timber(byte basePositionX, byte basePositionY)
{
  _baseX = basePositionX;
  _baseY = basePositionY;
  _x = basePositionX;
  _y = basePositionY;

  _life = 100;
  _strength = 56;
  _state = idle;

  _anim = 0;
  _movementAnim = 0;

  _sprite = 0;
}

byte Timber::X()
{
  return _x;
}

byte Timber::Y()
{
  return _y;
}

byte Timber::Life()
{
  return _life;
}

byte Timber::Strength()
{
  return _strength;
}

bool Timber::Sprite()
{
  return _anim >= 30;
}

void Timber::Update()
{
  // Sprite anim
  _anim = ++_anim;
  if (_anim >= ANIMATION_FRAME_DURATION)
    _anim = 0;

  // Movement anim
  if (_state != idle)
  {
    _movementAnim = ++_movementAnim;
    if (_movementAnim >= MOVEMENT_RECOVER)
    {
      UpdateState(idle);
      _movementAnim = 0;
    }
  }
};

void Timber::UpdateState(Movement state)
{
  if (_state != idle && state != idle)
  {
    // Wait before doing movement
    return;
  }

  _state = state;

  switch (_state)
  {
  case back:
    _x = 0;
    _y = _baseY;
    break;
  case up:
    _x = _baseX;
    _y = 0;
    break;
  case down:
    _x = _baseX;
    _y = 32;
    break;
  case idle:
    _x = _baseX;
    _y = _baseY;
    break;
  case attack:
    _x = _baseX + 30;
    _y = _baseY;
    GameManager& ptr = GameManager::Instance();
    ptr.MakeDamage(_strength);
    break;
  }
}

void Timber::TakeDamage(byte damage){
  _life -= damage;
}