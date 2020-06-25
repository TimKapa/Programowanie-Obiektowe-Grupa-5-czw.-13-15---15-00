#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Snake
{
public:
    void snakeInitate();
    int getVectorSize();
    int getPositionX(int i);
    int getPositionY(int i);
    void moveDown();
    void moveUp();
    void moveLeft();
    void moveRight();
    bool dead();
    int getSnake0();
    bool ifSnakeApple(int a);
    void eatApple();
    void SnakeCrossDown();
    void SnakeCrossUp();
    void SnakeCrossLeft();
    void SnakeCrossRight();

private:
    sf::Vector2f getPosition(int i);
    vector<int> snake;
    int fieldSize{ 30 };
    int a;

};