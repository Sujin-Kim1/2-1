#include "InputPane.h"
#include <unistd.h>
#include <ctime>

InputPane::InputPane(int x, int y, int width, int height) : Pane(x, y, width, height)
{
    box(m_pWindow, 0, 0);
    mvwprintw(m_pWindow, 0, 3, "< INPUT >");
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            m_attacked[i][j] = false;
        }
    }
}

InputPane::~InputPane()
{
}

void InputPane::Draw()
{
    wattron(m_pWindow, COLOR_PAIR(3));
    mvwprintw(m_pWindow, 1, 2, "Input position...(ex a3)");
    mvwprintw(m_pWindow, 2, 2, "Input : ");
    mvwprintw(m_pWindow, 3, 2, "");
    wattroff(m_pWindow, COLOR_PAIR(3));

    wrefresh(m_pWindow);
}

void InputPane::GetInput(char *input) {
    mvwprintw(m_pWindow, 2, 10, "      ");
    mvwgetnstr(m_pWindow, 2, 10, input, 2);
}

void InputPane::GetRandomInput(char *input)
{
    wrefresh(m_pWindow);
    usleep(300000);
    int x, y;
    srand(time(NULL));
    do
    {
        x = rand() % MAP_SIZE;
        y = rand() % MAP_SIZE;
    } while(m_attacked[x][y]);
    m_attacked[x][y] = true;
    input[0] = x + 'a';
    input[1] = y + '1';
}

void InputPane::SetAttacked(Position pos)
{
    if (OUT_OF_MAP(pos.x, pos.y))
    {
        return;
    }
    m_attacked[pos.x][pos.y] = true;
}