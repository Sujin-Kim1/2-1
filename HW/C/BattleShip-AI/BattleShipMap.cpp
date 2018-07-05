#include "BattleShipMap.h"

BattleShipMap::BattleShipMap()
{
}

BattleShipMap::BattleShipMap(int x, int y, int roll)
    : Pane(x, y, MAP_SIZE + 3, MAP_SIZE + 2)
{
    box(m_pWindow, 0, 0);
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            m_mapData[i][j] = DATA_NONE;
        }
    }

    for (int i = 0; i < MAP_SIZE; i++)
    {
        mvprintw(i + 1 + m_y, m_x - 1, "%c", 'A' + i);
        mvprintw(m_y + m_height, m_x + 2 + i, "%d", 1 + i);
    }
    mvwprintw(m_pWindow, 0, 1, (roll == DEFENDER) ? "<DEFENDER>" : "<ATTACKER>");
}

BattleShipMap::~BattleShipMap()
{
}

void BattleShipMap::Draw()
{
    wattron(m_pWindow, COLOR_PAIR(1));
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            switch (m_mapData[i][j])
            {
            case DATA_NONE:
                mvwprintw(m_pWindow, i + 1, j + 2, "%c", '.');
                break;
            case AIRCRAFT:
                mvwprintw(m_pWindow, i + 1, j + 2, "%c", 'A');
                break;
            case BATTLESHIP:
                mvwprintw(m_pWindow, i + 1, j + 2, "%c", 'B');
                break;
            case CRUISER:
                mvwprintw(m_pWindow, i + 1, j + 2, "%c", 'C');
                break;
            case DESTROYER:
                mvwprintw(m_pWindow, i + 1, j + 2, "%c", 'D');
                break;
            case HITFLAG:
                mvwprintw(m_pWindow, i + 1, j + 2, "%c", 'O');
                break;
            case MISSFLAG:
                mvwprintw(m_pWindow, i + 1, j + 2, "%c", 'X');
                break;
            }
        }
    }
    wattroff(m_pWindow, COLOR_PAIR(1));
    wrefresh(m_pWindow);
}

ShipType BattleShipMap::GetMapData(const Position &pos) const
{
    if (0 <= pos.x && pos.x < MAP_SIZE &&
        0 <= pos.y && pos.y < MAP_SIZE)
    {
        return m_mapData[pos.x][pos.y];
    }
    return DATA_ERROR;
}

void BattleShipMap::SetMapData(const Position &pos, ShipType type)
{
    if (0 <= pos.x && pos.x < MAP_SIZE &&
        0 <= pos.y && pos.y < MAP_SIZE)
    {
        m_mapData[pos.x][pos.y] = type;
    }
}
