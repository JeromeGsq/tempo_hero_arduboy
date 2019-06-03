// gameManager.h
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <Arduboy2.h>
#include "Tinyfont.h"

#include "timber.h"
#include "enemy.h"

class GameManager
{
private:
    static GameManager m_instance;

    Timber timber;
    Enemy enemy;

public:
    static GameManager& Instance();

    GameManager();

    void MakeDamage(byte damage);

    void Update(Arduboy2 &ab);
    void Display(Arduboy2 &ab, Tinyfont &tf);
};

#endif