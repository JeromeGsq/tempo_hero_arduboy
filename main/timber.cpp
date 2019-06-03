#include "timber.hpp"
#include "gameManager.hpp"

Timber::Timber(byte basePositionX, byte basePositionY, byte life, byte strength) : Entity(basePositionX, basePositionY, life, strength)
{
}

void Timber::Update()
{
  Entity::Update();

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
    _y = _baseY-14;
    break;
  case down:
    _x = _baseX;
    _y = _baseY+14;
    break;
  case idle:
    _x = _baseX;
    _y = _baseY;
    break;
  case attack:
    _x = _baseX + 30;
    _y = _baseY;
    
    // Apply damage to enemy
    GameManager::get()->MakeDamage(_strength, entityEnemy);
    break;
  }
}