#ifndef SHIP_H
#define SHIP_H

#include "CommonDefine.h"
#include <vector>

class Ship
{
public:
  Ship(int length);
  Ship();

  virtual ~Ship();

  ShipType GetType() const { return m_Type; };
  std::vector<Position> GetPosition() const { return m_Pos; };
  int GetLength() const { return m_length; };
  int GetHP() const { return m_HP; };

  void Attacked();
  void SetPosition(int index, const Position &pos);
  bool IsDeadShip() { return m_HP == 0; };

protected:
  ShipType m_Type;
  int m_length;
  int m_HP;
  std::vector<Position> m_Pos;
};

#endif // SHIP_H
