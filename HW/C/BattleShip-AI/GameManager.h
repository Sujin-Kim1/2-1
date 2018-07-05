#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "CommonDefine.h"

class Player;
class Ship;

class GameManager
{
  public:
    GameManager();
    ~GameManager();

    void Init();
    HitResult AttackByInput(Position pos, ShipType &type);
    void Render();
    int GetTurn() const { return m_Turn; };
    void Addturn();
    bool IsAttacked(const Position &pos) const;

  protected:
    Player *m_pAttacker;
    Player *m_pDefender;
    GameMode m_GameMode;
    int m_Turn;
    SHIPS m_Ships;
};

#endif // GAMEMANAGER_H
