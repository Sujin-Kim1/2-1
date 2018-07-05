#include "Ship.h"
#include "CommonDefine.h"

Ship::Ship(int length)
    : m_length(length), m_HP(length)
{
    m_Pos.resize(length);
    // m_Pos.reserve(length)와 차이점 구분하기 !!
}

Ship::Ship()
{
}

Ship::~Ship()
{
}

void Ship::SetPosition(int index, const Position &pos)
{
    m_Pos[index] = pos;
}

void Ship::Attacked()
{
    if (m_HP > 0)
    {
        m_HP--;
    }
}
