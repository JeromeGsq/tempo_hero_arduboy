#include "gameManager.h"

GameManager GameManager::m_instance=GameManager();

GameManager& GameManager::Instance()
{
    return m_instance;
}

GameManager::GameManager(): timber(16, 16),  enemy(80, 10)
{
}

void GameManager::MakeDamage(byte damage){
    enemy.TakeDamage(damage);
}

void GameManager::Update(Arduboy2 &ab)
{
    if (ab.justPressed(LEFT_BUTTON))
    {
        timber.UpdateState(back);
    }
    else if (ab.justPressed(UP_BUTTON))
    {
        timber.UpdateState(up);
    }
    else if (ab.justPressed(DOWN_BUTTON))
    {
        timber.UpdateState(down);
    }
    else if (ab.justPressed(B_BUTTON))
    {
        timber.UpdateState(attack);
    }
}

void GameManager::Display(Arduboy2 &ab, Tinyfont &tf)
{
    // draw Timber
    timber.Update();
    ab.drawBitmap(timber.X(), timber.Y(), timber.Sprite() ? timber1 : timber2, 34, 34);

    // draw Enemy
    enemy.UpdateSprite();
    ab.drawBitmap(enemy.X(), enemy.Y(), enemy.Sprite() == 0 ? mushroom1 : mushroom2, 42, 41);

    // draw UI
    // player life
    tf.setCursor(0, 60);
    tf.print(timber.Life());

    // player life
    tf.setCursor(110, 60);
    tf.print(enemy.Life());
}