#include "gameManager.hpp"

GameManager *GameManager::_singleton = new GameManager;

GameManager::GameManager() : _player(16, 16, 100, 10), _enemy(80, 10, 100, 15)
{
}

void GameManager::MakeDamage(byte damage, EntityEnum entity)
{
    if (entity == entityEnemy)
    {
        _enemy.TakeDamage(damage);
    }
    else if (entity == entityPlayer)
    {
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
    tf.setCursor(0, 0);
    tf.print(_player.Life());

    // enemy life
    tf.setCursor(128 - 3 * CHAR_LENGHT, 0);
    tf.print(_enemy.Life());

    for (int i = 0; i <= ACTION_BAR_HEIGHT; i++)
    {
        ab.drawLine(0, 64 - i, 128, 64 - i, i == ACTION_BAR_HEIGHT ? WHITE : BLACK);
    }

    // player action delay
    tf.setCursor(ACTION_BAR_POSX, 54);
    tf.print("ACTION:");

    ab.drawRect(ACTION_BAR_POSX, 61, ACTION_BAR_LENGTH + 1, 3, _player.MovementAnim() % 7 ? BLACK : WHITE);
    ab.drawLine(ACTION_BAR_POSX + 1, 62, _player.MovementAnim() == 0 ? ACTION_BAR_LENGTH + ACTION_BAR_POSX : ((double)_player.MovementAnim() / (double)MOVEMENT_RECOVER) * ACTION_BAR_LENGTH + ACTION_BAR_POSX, 62);
}