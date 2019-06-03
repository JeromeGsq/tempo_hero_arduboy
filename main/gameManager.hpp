// gameManager.h
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <Arduboy2.h>
#include "Tinyfont.h"

#include "timber.hpp"
#include "enemy.hpp"

enum EntityEnum { entityPlayer, entityEnemy};

class GameManager
{
private:
    GameManager(const GameManager &) = delete;
    GameManager &operator=(const GameManager &) = delete;
    static GameManager *_singleton;
    GameManager();

    Timber _player;
    Enemy _enemy;

public:
    static GameManager *get()
    {
        if (!_singleton)
            _singleton = new GameManager;
        return _singleton;
    }

    void MakeDamage(byte damage, EntityEnum entity);

    void Update(Arduboy2 &ab);
    void Display(Arduboy2 &ab, Tinyfont &tf);
};

#endif