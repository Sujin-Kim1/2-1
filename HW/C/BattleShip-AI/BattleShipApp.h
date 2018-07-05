#ifndef BATTLESHIPAPP_H
#define BATTLESHIPAPP_H

#include <ncurses.h>
#include "CommonDefine.h"

class StatPane;
class InputPane;
class GameManager;

class BattleShipApp
{
public:
  BattleShipApp();
  ~BattleShipApp();

  void Play();
  void PrintResult(const HitResult& hitResult, const ShipType& type, const char * input) const;
  void PrintAverageTurn();

protected:
  void Init();
  void Render();
  void SetGameMode();
  void Destroy();

protected:
  StatPane *m_pStatPane;
  InputPane *m_pInputPane;
  GameManager *m_pGameManager;
  GameMode m_gameMode;
  Position m_directions[4];
  int m_totalTurn;
};

#endif //BATTLESHIPAPP_H
