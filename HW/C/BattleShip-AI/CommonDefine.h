#ifndef COMMONDEFINE_H
#define COMMONDEFINE_H

#include <vector>
#include <iostream>

struct Position
{
    int x;
    int y;
    Position() : x(0), y(0) {}
    Position(int x, int y) : x(x), y(y) {}
    Position operator+(const Position &pos)
    {
        Position retPos;
        retPos.x = x + pos.x;
        retPos.y = y + pos.y;
        return retPos;
    }

    Position operator-(const Position &pos)
    {
        Position retPos;
        retPos.x = x - pos.x;
        retPos.y = y - pos.y;
        return retPos;
    }

    bool operator==(const Position &pos)
    {
        return x == pos.x && y == pos.y;
    }

    bool operator!=(const Position &pos)
    {
        return !(*this == pos);
    }

    friend std::ostream &operator<<(std::ostream &os, const Position &pos)
    {
        os << "x: " << pos.x << " ";
        os << "y: " << pos.y;
        return os;
    }
};

enum ShipType
{
    DATA_ERROR = -1,
    DATA_NONE,
    AIRCRAFT,
    BATTLESHIP,
    CRUISER,
    DESTROYER,
    HITFLAG,
    MISSFLAG
};

enum HitResult
{
    POS_ERROR = -1,
    MISS,
    HIT,
    DESTROY,
    GAME_CLEAR
};

enum GameMode
{
    PLAY_INPUT,
    PLAY_RANDOM,
};

#define SHIPS std::vector<Ship *>
#define DEFENDER 0
#define ATTACKER 1
#define OUT_OF_MAP(x, y) x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE
static const int MAP_SIZE = 8;

#endif // COMMONDEFINE_H
