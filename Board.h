#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Board : public sf::Drawable
{
public:
    void boardInitate(int a, int b);
    int getNumberFieldsX();
    int getNumberFieldsY();
    void showSnake();
    void clear();
    void showApple();

private:
    int fieldsX{ 30 };
    int fieldsY{ 30 };
    int fieldSizeX{ 29 };
    int fieldSizeY{ 29 };
    sf::Vector2f fieldSize{ fieldSizeX, fieldSizeY };
    sf::RectangleShape shape;
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};

