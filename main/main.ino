using namespace std;

#include <Arduboy2.h>
#include "Tinyfont.h"

Arduboy2 ab;
Tinyfont tf = Tinyfont(ab.sBuffer, 128, 64);

#include "gameManager.hpp"
#include "timber.hpp"
#include "enemy.hpp"

void setup()
{
  ab.begin();
  start();
  ab.setFrameRate(60);
  ab.clear();
}

void loop()
{
  if (!(ab.nextFrame()))
    return;

  ab.pollButtons();

  ab.clear();

  run();
  display();

  ab.display();
}

void start()
{
}

void run()
{
  GameManager::get()->Update(ab);
}

void display()
{
  GameManager::get()->Display(ab, tf);
}