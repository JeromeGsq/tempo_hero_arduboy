#include "gameManager.hpp"

GameManager *GameManager::_singleton = new GameManager;

GameManager::GameManager(): _player(16, 16, 100, 10),  _enemy(80, 10, 100, 15)
{
}

void GameManager::MakeDamage(byte damage, EntityEnum entity){
    if(entity == entityEnemy){
        _enemy.TakeDamage(damage);
    }else if(entity == entityPlayer){
        _player.TakeDamage(damage);
    }
}

void GameManager::Update(Arduboy2 &ab)
{
    if (ab.justPressed(LEFT_BUTTON))
    {
        _player.UpdateState(back);
    }
    else if (ab.justPressed(UP_BUTTON))
    {
        _player.UpdateState(up);
    }
    else if (ab.justPressed(DOWN_BUTTON))
    {
        _player.UpdateState(down);
    }
    else if (ab.justPressed(B_BUTTON))
    {
        _player.UpdateState(attack);
    }
}

void GameManager::Display(Arduboy2 &ab, Tinyfont &tf)
{
    // draw Timber
    _player.Update();
    ab.drawBitmap(_player.X(), _player.Y(), _player.Sprite() ? timber1 : timber2, 34, 34);

    // draw Enemy
    _enemy.Update();
    ab.drawBitmap(_enemy.X(), _enemy.Y(), _enemy.Sprite() == 0 ? mushroom1 : mushroom2, 42, 41);

    // draw UI
    // player life
    tf.setCursor(0, 60);
    tf.print(_player.Life());

    // player life
    tf.setCursor(110, 60);
    tf.print(_enemy.Life());
}