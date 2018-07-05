#include "StatPane.h"

StatPane::StatPane(int x, int y, int width, int height)
    : Pane(x, y, width, height)
{
    box(m_pWindow, 0, 0);
    m_firstDestroyer = true;
    mvwprintw(m_pWindow, 0, 3, "< STATUS >");
}

StatPane::~StatPane()
{
}

void StatPane::Draw()
{
    wattron(m_pWindow, COLOR_PAIR(2));
    mvwprintw(m_pWindow, 1, 2, "Turn : ");
    mvwprintw(m_pWindow, 2, 2, "AIRCRAFT : AAAAA");
    mvwprintw(m_pWindow, 3, 2, "BATTLESHIP : BBBB");
    mvwprintw(m_pWindow, 4, 2, "CRUSIER : CCC");
    mvwprintw(m_pWindow, 5, 2, "DESTROYER : DD DD");
    wattroff(m_pWindow, COLOR_PAIR(2));

    wrefresh(m_pWindow);
}

void StatPane::PrintTurn(int turn) const {
    wattron(m_pWindow, COLOR_PAIR(2));
    mvwprintw(m_pWindow, 1, 2, "Turn : %d", turn);
    wattroff(m_pWindow, COLOR_PAIR(2));

    wrefresh(m_pWindow);
}

void StatPane::PrintDestroy(ShipType type) {
    wattron(m_pWindow, COLOR_PAIR(4));
    switch (type) {
        case AIRCRAFT:
            mvwprintw(m_pWindow, 2, 13, "AAAAA");
            break;
        case BATTLESHIP:
            mvwprintw(m_pWindow, 3, 15, "BBBB");
            break;
        case CRUISER:
            mvwprintw(m_pWindow, 4, 12, "CCC");
            break;
        case DESTROYER:
            if (m_firstDestroyer) {
                mvwprintw(m_pWindow, 5, 14, "DD");
                m_firstDestroyer = false;
            }
            else {
                mvwprintw(m_pWindow, 5, 17, "DD");
            }
            break;
    }
    wattroff(m_pWindow, COLOR_PAIR(4));

    wrefresh(m_pWindow);
}
