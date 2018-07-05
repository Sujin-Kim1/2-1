#ifndef BATTLESHIPMAP_H
#define BATTLESHIPMAP_H

#include "CommonDefine.h"
#include "Pane.h"

class BattleShipMap : public Pane
{
  public:
    BattleShipMap();
    BattleShipMap(int x, int y, int roll);
    ~BattleShipMap();
    virtual void Draw();

    ShipType GetMapData(const Position &pos) const;
    void SetMapData(const Position &pos, ShipType type);

  protected:
    ShipType m_mapData[MAP_SIZE][MAP_SIZE];
};

#endif //BATTLESHIPMAP_H
