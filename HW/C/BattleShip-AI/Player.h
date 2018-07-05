#ifndef PLAYER_H
#define PLAYER_H

#include "CommonDefine.h"
class BattleShipMap;
class Ship;

class Player
{
  public:
    Player(int x, int y, int roll);
    ~Player();

    void Render();
    ShipType GetMapData(const Position &pos) const;

    // Defender
    void SetupShips(const SHIPS &ships);
    SHIPS &GetShips() { return m_ships; };

    // Attacker
    void Attack();
    void SetHitResult(const Position &pos, ShipType type);

  protected:
    BattleShipMap *m_pMap;
    SHIPS m_ships;
};

#endif //PLAYER_H