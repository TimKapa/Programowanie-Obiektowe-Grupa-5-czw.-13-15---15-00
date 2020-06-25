#include "Board.h"

void Board::boardInitate(int a, int b)
{
    shape.setSize(fieldSize);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(a, b);
}

int Board::getNumberFieldsX()
{
    return fieldsX;
}

int Board::getNumberFieldsY()
{
    return fieldsY;
}

void Board::showSnake()
{
    this->shape.setFillColor(sf::Color::Magenta);
}

void Board::clear()
{
    this->shape.setFillColor(sf::Color::White);
}

void Board::showApple()
{
    this->shape.setFillColor(sf::Color::Green);
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->shape, state);
}
