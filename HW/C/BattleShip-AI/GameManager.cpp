#include "GameManager.h"
#include "Ship.h"
#include "Player.h"
#include "Aircraft.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"

GameManager::GameManager()
{
    m_pAttacker = NULL;
    m_pDefender = NULL;
    m_Turn = 0;
}

GameManager::~GameManager()
{
    if (m_pAttacker)
    {
        delete m_pAttacker;
        m_pAttacker = NULL;
    }
    if (m_pDefender)
    {
        delete m_pDefender;
        m_pDefender = NULL;
    }
}

void GameManager::Init()
{
    m_pDefender = new Player(4, 3, DEFENDER);
    m_pAttacker = new Player(4, 16, ATTACKER);

    // 배를 배치
    std::vector<Ship *> vecShip;
    vecShip.push_back(new Aircraft());
    vecShip.push_back(new BattleShip());
    vecShip.push_back(new Cruiser());
    vecShip.push_back(new Destroyer());
    vecShip.push_back(new Destroyer());

    m_pDefender->SetupShips(vecShip);
}

HitResult GameManager::AttackByInput(Position pos, ShipType &type)
{
    if (OUT_OF_MAP(pos.x, pos.y))
    {
        return POS_ERROR;
    }
    SHIPS &pShips = m_pDefender->GetShips();
    for (auto pShip : pShips)
    {
        for (Position shipPos : pShip->GetPosition())
        {
            if (shipPos == pos)
            {
                pShip->Attacked();
                if (pShip->GetHP() == 0)
                {
                    type = pShip->GetType();
                    for (Position destroyedPos : pShip->GetPosition())
                    {
                        m_pAttacker->SetHitResult(destroyedPos, type);
                    }
                    Render();
                    bool gameClear = true;
                    for (auto pTempShip : pShips)
                    {
                        if (!pTempShip->IsDeadShip())
                        {
                            gameClear = false;
                            break;
                        }
                    }
                    if (gameClear)
                    {
                        return GAME_CLEAR;
                    }
                    return DESTROY;
                }
                else
                {
                    m_pAttacker->SetHitResult(pos, HITFLAG);
                    Render();
                    return HIT;
                }
            }
        }
    }
    m_pAttacker->SetHitResult(pos, MISSFLAG);
    Render();
    return MISS;
}

void GameManager::Render()
{
    m_pDefender->Render();
    m_pAttacker->Render();
}

void GameManager::Addturn()
{
    m_Turn++;
}

bool GameManager::IsAttacked(const Position &pos) const
{
    return m_pAttacker->GetMapData(pos) != DATA_NONE;
}
