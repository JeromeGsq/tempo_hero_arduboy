// entity.h
#ifndef Entity_H
#define Entity_H

#include <Arduboy2.h>

#define ANIMATION_FRAME_DURATION 40
#define MOVEMENT_RECOVER 45

enum Movement
{
    up,
    back,
    down,
    idle,
    attack
};

class Entity
{
protected:
    byte _baseX;
    byte _baseY;
    byte _x;
    byte _y;

    byte _life;
    byte _strength;
    Movement _state;

    byte _anim;
    byte _movementAnim;

    byte _sprite;

public:
    Entity(byte basePositionX, byte basePositionY, byte life, byte strength);

    byte X();
    byte Y();

    byte Life();
    byte Strength();

    byte Anim();
    byte MovementAnim();

    bool Sprite();

    void TakeDamage(byte damage);

    void Update();
    void UpdateState(Movement state);
};
#endif