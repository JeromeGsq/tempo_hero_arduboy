using namespace std;

#include <Arduboy2.h>
#include "Tinyfont.h"

Arduboy2 ab;
Tinyfont tf = Tinyfont(ab.sBuffer, 128, 64);

#include "gameManager.h"
#include "timber.h"
#include "enemy.h"

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

GameManager gameManager;

void start()
{
}

void run()
{
  gameManager.Update(ab);
}

void display()
{
  gameManager.Display(ab, tf);
}