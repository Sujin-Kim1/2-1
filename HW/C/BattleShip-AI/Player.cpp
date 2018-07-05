#include "Player.h"
#include "BattleShipMap.h"
#include "Ship.h"
#include <time.h>

Player::Player(int x, int y, int roll)
{
    m_pMap = new BattleShipMap(x, y, roll);
}

Player::~Player()
{
    delete m_pMap;

    for (auto pShip : m_ships)
    {
        if (pShip)
        {
            delete pShip;
        }
    }
    m_ships.clear();
}

ShipType Player::GetMapData(const Position &pos) const
{
    return m_pMap->GetMapData(pos);
}

void Player::Render()
{
    m_pMap->Draw();
}

void Player::SetupShips(const SHIPS &ships)
{
    m_ships = ships;
    srand(time(NULL));

    for (auto pShip : m_ships)
    {
        while (true)
        {
            Position pos;
            pos.x = rand() % MAP_SIZE;
            pos.y = rand() % MAP_SIZE;
            ShipType dataType = m_pMap->GetMapData(pos);
            if (dataType != DATA_NONE)
            {
                continue;
            }
            Position dir;
            if (rand() % 2)
            {
                dir.x = rand() % 2 ? 1 : -1;
            }
            else
            {
                dir.y = rand() % 2 ? 1 : -1;
            }

            bool bSuccess = true;
            for (int i = 0; i < pShip->GetLength(); i++)
            {
                pos = pos + dir;
                ShipType dataType = m_pMap->GetMapData(pos);
                if (dataType != DATA_NONE)
                {
                    bSuccess = false;
                    break;
                }
                pShip->SetPosition(i, pos);
            }
            if (bSuccess)
            {
                for (Position position : pShip->GetPosition())
                {
                    m_pMap->SetMapData(position, pShip->GetType());
                }
                break;
            }
            else
            {
                continue;
            }
        }
    }
}

void Player::SetHitResult(const Position &pos, ShipType type)
{
    m_pMap->SetMapData(pos, type);
}
