#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <time.h>
#include "Board.h"
#include "Snake.h"
#include "Apple.h"

using namespace std;

class SFMLshow
{
public:
    int play();

private:
    const int windowSizeX{ 900 };
    const int windowSizeY{ 900 };
    Board board[30][30];
    Snake snake;
    Apple apple;
    int destination{ 0 };
    int prev_dest{ 0 };
    int sleep{ 1000 };

};
