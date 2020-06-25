#include "Apple.h"
#include <cstdlib>

int Apple::appleInitate()
{
    int randomLocationSeed;
    srand(time(NULL));
    int a = rand() % 150;
    int b = rand() % 150;
    int c = rand() % 150;
    int d = rand() % 150;
    int e = rand() % 150;
    int f = rand() % 150;
    randomLocationSeed = a+b+c+d+e+f;
    return randomLocationSeed;
}

sf::Vector2f Apple::coordinates()
{
    int a = XandY;
    float  x{ 0 }, y{ 0 };
    x = a % 30;
    y = (a - x) / 30;
    sf::Vector2f coordinates{ x , y };
    return coordinates;
}

int Apple::getApplePositionX()
{
    sf::Vector2f coordinatesX = coordinates();
    int x = coordinatesX.x;
    return x;
}

int Apple::getApplePositionY()
{
    sf::Vector2f coordinatesY = coordinates();
    int y = coordinatesY.y;
    return y;
}
