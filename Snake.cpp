#include "Snake.h"

void Snake::snakeInitate()
{
    snake.push_back(0);
    snake.push_back(1);
    snake.push_back(2);
    snake.push_back(3);
    snake.push_back(4);
    snake.push_back(5);
    snake.push_back(6);
}

sf::Vector2f Snake::getPosition(int i)
{
    float  x{ 0 }, y{ 0 };
    int a{ 0 };
    a = snake[i];
    x = a % 30;
    y = (a - x) / 30;
    sf::Vector2f coordinates{ x , y  };
    //cout << " a: " << a << " coords x: " << coordinates.x << " coords y: " << coordinates.y;
    // Czysto diagnostyczne do wykrywania bledu
    return coordinates;
}

int Snake::getVectorSize()
{
    return snake.size();
}

int Snake::getPositionX(int i)
{
    sf::Vector2f coordinates = getPosition(i);
    int x = coordinates.x;
    return x;
}

int Snake::getPositionY(int i)
{
    sf::Vector2f coordinates = getPosition(i);
    int y = coordinates.y;
    return y;
}

void Snake::moveDown()
{
    int a = snake[getVectorSize() - 1];
    for (int i = 1; i < getVectorSize(); i++)
    {
        this->snake[getVectorSize() - i] = snake[getVectorSize() - i - 1];
    }
    this->snake[0] = snake[0] + 30;
}

void Snake::moveUp()
{
    int a = snake[getVectorSize() - 1];
    for (int i = 1; i < getVectorSize(); i++)
    {
        this->snake[getVectorSize() - i] = snake[getVectorSize() - i - 1];
    }
    this->snake[0] = snake[0] - 30;
}

void Snake::moveLeft()
{
    int a = snake[getVectorSize() - 1];
    for (int i = 1; i < getVectorSize(); i++)
    {
        this->snake[getVectorSize() - i] = snake[getVectorSize() - i - 1];
    }
    this->snake[0] = snake[0] - 1;
}

void Snake::moveRight()
{
    int a = snake[getVectorSize() - 1];
    for (int i = 1; i < getVectorSize(); i++)
    {
        this->snake[getVectorSize() - i] = snake[getVectorSize() - i - 1];
    }
    this->snake[0] = snake[0] + 1;
}

bool Snake::dead()
{
    for(int i=1; i<getVectorSize(); i++)
    {
        if (snake[0] == snake[i]) return true;
    }
}

int Snake::getSnake0()
{
    return snake[0];
}

bool Snake::ifSnakeApple(int a)
{
    if (getSnake0() == a) return true;
    else return false;
}

void Snake::eatApple()
{
    snake.push_back(a);
}

void Snake::SnakeCrossDown()
{
    int a = snake[getVectorSize() - 1];
    for (int i = 1; i < getVectorSize(); i++)
    {
        this->snake[getVectorSize() - i] = snake[getVectorSize() - i - 1];
    }
    int b = getPositionX(0);
    snake[0] = b;
}

void Snake::SnakeCrossUp()
{
    int a = snake[getVectorSize() - 1];
    for (int i = 1; i < getVectorSize(); i++)
    {
        this->snake[getVectorSize() - i] = snake[getVectorSize() - i - 1];
    }
    int b = getPositionX(0);
    snake[0] = b + 870;
}

void Snake::SnakeCrossLeft()
{
    int a = snake[getVectorSize() - 1];
    for (int i = 1; i < getVectorSize(); i++)
    {
        this->snake[getVectorSize() - i] = snake[getVectorSize() - i - 1];
    }
    int b = getPositionY(0);
    snake[0] = (b*30)+29;
}

void Snake::SnakeCrossRight()
{
    int a = snake[getVectorSize() - 1];
    for (int i = 1; i < getVectorSize(); i++)
    {
        this->snake[getVectorSize() - i] = snake[getVectorSize() - i - 1];
    }
    int b = getPositionY(0);
    snake[0] = b*30;
}