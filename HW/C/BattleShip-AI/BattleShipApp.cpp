#include "BattleShipApp.h"
#include "BattleShipMap.h"
#include "StatPane.h"
#include "InputPane.h"
#include "GameManager.h"
#include <unistd.h>

BattleShipApp::BattleShipApp()
{
    m_pStatPane = NULL;
    m_pInputPane = NULL;
    m_pGameManager = NULL;
    m_totalTurn = 0;
    m_directions[0] = Position(-1, 0);
    m_directions[1] = Position(1, 0);
    m_directions[2] = Position(0, -1);
    m_directions[3] = Position(0, 1);
}

BattleShipApp::~BattleShipApp()
{
    if (m_pStatPane)
    {
        delete m_pStatPane;
        m_pStatPane = NULL;
    }
    if (m_pInputPane)
    {
        delete m_pInputPane;
        m_pInputPane = NULL;
    }
    if (m_pGameManager) 
    {
        delete m_pGameManager;
        m_pGameManager = NULL;
    }
}

void BattleShipApp::PrintResult(const HitResult& hitResult, const ShipType& type, const char *input) const 
{
    switch (hitResult)
    {
        case POS_ERROR:
            mvwprintw(m_pInputPane->GetWindow(), 3, 2, "Incorrect Position         ");
            break;
        case MISS:
            mvwprintw(m_pInputPane->GetWindow(), 3, 2, "(%c, %c) is missed          ", input[0], input[1]);
            break;
        case HIT:
            mvwprintw(m_pInputPane->GetWindow(), 3, 2, "(%c, %c) is hit            ", input[0], input[1]);
            break;
        case GAME_CLEAR:
        case DESTROY:
            mvwprintw(m_pInputPane->GetWindow(), 3, 2, "Destroyed                 ");
            m_pStatPane->PrintDestroy(type);
            break;
    } 
}

void BattleShipApp::PrintAverageTurn()
{
    mvwprintw(m_pInputPane->GetWindow(), 3, 2, "Average Turn : %d  ", m_totalTurn / 10);
    wrefresh(m_pInputPane->GetWindow());
    getch();
    endwin();
}

void BattleShipApp::Play()
{
    Init();
    Render();
    SetGameMode();
    for (int game = 1; game <= 10; game++)
    {
        mvprintw(1, 24, "- Game : %d", game);
        Init();
        Render();
        Destroy();
    }
    PrintAverageTurn();
}

void BattleShipApp::Init()
{
    initscr();
    start_color();
    cbreak();
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);

    m_pStatPane = new StatPane(30, 3, 30, 7);
    m_pInputPane = new InputPane(30, 15, 30, 5);

    m_pGameManager = new GameManager();
    m_pGameManager->Init();
}

void BattleShipApp::Render()
{
    mvprintw(1, 1, "<< BATTLE SHIP GAME >>");

    m_pGameManager->Render();
    m_pStatPane->Draw();
    m_pInputPane->Draw();

    refresh();
}

void BattleShipApp::SetGameMode()
{
    char gameMode;
    bool bsuccess = false;
    while (!bsuccess)
    {
        mvwprintw(m_pInputPane->GetWindow(), 3, 2, "1. Input Mode / 2. AI Mode ");
        gameMode = mvwgetch(m_pInputPane->GetWindow(), 2, 10);
        wrefresh(m_pInputPane->GetWindow());
        switch(gameMode) {
            case '1':
                m_gameMode = PLAY_INPUT;
                mvwprintw(m_pInputPane->GetWindow(), 3, 2, "Input Mode selected        ");
                bsuccess = true;
                break;
            case '2':
                m_gameMode = PLAY_RANDOM;
                mvwprintw(m_pInputPane->GetWindow(), 3, 2, "AI Mode selected          ");
                bsuccess = true;
                break;
        }
    }
}

void BattleShipApp::Destroy()
{
    HitResult hitResult;
    do
    {
        char input[2];
        if (m_gameMode == PLAY_INPUT)
        {
            m_pInputPane->GetInput(input);
        }
        else if (m_gameMode == PLAY_RANDOM)
        {
            m_pInputPane->GetRandomInput(input);
        }
        if (OUT_OF_MAP(input[0] - 'a', input[1] - '1'))
        {
            mvwprintw(m_pInputPane->GetWindow(), 3, 2, "Incorrect Input            ");
            continue;
        }
        else
        {
            Position target(input[0] - 'a', input[1] - '1');
            if (m_pGameManager->IsAttacked(target))
            {
                mvwprintw(m_pInputPane->GetWindow(), 3, 2, "Already Attacked Position  ");
                continue;
            }
            m_pGameManager->Addturn();
            m_pStatPane->PrintTurn(m_pGameManager->GetTurn());
            wrefresh(m_pStatPane->GetWindow());
            ShipType type = DATA_NONE;
            hitResult = m_pGameManager->AttackByInput(target, type);
            PrintResult(hitResult, type, input);
            if (m_gameMode == PLAY_RANDOM)
            {            
                if (hitResult == HIT)
                {
                    bool destroyed = false;
                    for (Position direction : m_directions)
                    {
                        hitResult = HIT;
                        Position temp = target;
                        while (hitResult != MISS)
                        {
                            temp = temp + direction;
                            if (OUT_OF_MAP(temp.x, temp.y) || m_pGameManager->IsAttacked(temp))
                            {
                                break;
                            }
                            usleep(300000);
                            m_pGameManager->Addturn();
                            m_pStatPane->PrintTurn(m_pGameManager->GetTurn());
                            wrefresh(m_pStatPane->GetWindow());
                            hitResult = m_pGameManager->AttackByInput(temp, type);
                            m_pInputPane->SetAttacked(temp);
                            PrintResult(hitResult, type, input);
                            if (hitResult == DESTROY || hitResult == GAME_CLEAR)
                            {
                                destroyed = true;
                                break;
                            }
                        }
                        if (destroyed)
                        {
                            break;
                        }
                    }
                }
            }
        }
    } while (m_pGameManager->GetTurn() <= MAP_SIZE * MAP_SIZE && hitResult != GAME_CLEAR);
    m_totalTurn += m_pGameManager->GetTurn();
}
