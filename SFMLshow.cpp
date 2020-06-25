#include "SFMLshow.h"

int SFMLshow::play()
{
    for (int i = 0; i < board[0][0].getNumberFieldsY(); i++)
    {
        for (int j = 0; j < board[0][0].getNumberFieldsX(); j++)
        {
            board[i][j].boardInitate(i * board[0][0].getNumberFieldsY(), j * board[0][0].getNumberFieldsX());
        }
    }
    snake.snakeInitate();
    sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), "SNAKE");
    while (window.isOpen())
    {
        window.setFramerateLimit(200);
        sf::Event event;
        prev_dest = destination;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
            if (prev_dest == 0)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                {
                    destination = 0;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                {
                    destination = 3;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                {
                    destination = 2;
                }
            }
            if (prev_dest == 1)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                {
                    destination = 1;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                {
                    destination = 2;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                {
                    destination = 3;
                }
            }
            if (prev_dest == 2)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                {
                    destination = 0;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                {
                    destination = 1;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                {
                    destination = 2;
                }
            }
            if (prev_dest == 3)
            {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                {
                    destination = 0;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                {
                    destination = 1;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                {
                    destination = 3;
                }
            }
        }
        window.clear(sf::Color::Black);
        for (int i = 0; i < board[0][0].getNumberFieldsY(); i++)
        {
            for (int j = 0; j < board[0][0].getNumberFieldsX(); j++)
            {
                this->board[i][j].clear();
            }
        }
        if (destination == 0) {
            if (snake.getPositionY(0) == board[0][0].getNumberFieldsY() - 1) snake.SnakeCrossDown();
            else snake.moveDown();
        }
        else if (destination == 1) {
            if (snake.getPositionY(0) == 0) snake.SnakeCrossUp();
            else snake.moveUp();
        }
        else if (destination == 2) {
            if (snake.getPositionX(0) == 0) snake.SnakeCrossLeft();
            else snake.moveLeft();
        }
        else if (destination == 3) {
            if (snake.getPositionX(0) == board[0][0].getNumberFieldsX()-1) snake.SnakeCrossRight();
            else snake.moveRight();
        }
        if (snake.dead() == true)
        {
            window.clear(sf::Color::Blue);
            sf::Font font;
            if(!font.loadFromFile("C:/Users/gilda/Desktop/II semestr/Programowanie obiektowe/Czcionki/arial.ttf"))
                exit(-1);
            sf::Text text1("GAME \nOVER", font, 300);
            window.draw(text1);
            window.display();
            Sleep(3500);
            window.close();
        }
        for (int i = 0; i < snake.getVectorSize(); i++)
        {
            board[snake.getPositionX(i)][snake.getPositionY(i)].showSnake();
        }
        board[apple.getApplePositionX()][apple.getApplePositionY()].showApple();
        if (snake.ifSnakeApple(apple.XandY) == true)
        {
            //snake.eatApple();
            apple.XandY = apple.appleInitate();
            //////////
            for (int i = 0; i < snake.getVectorSize(); i++)
            {
                if(snake.getPositionX(i) == apple.getApplePositionX() && snake.getPositionY(i) == apple.getApplePositionY())
                {
                    apple.XandY = apple.appleInitate();
                }
            }
            //////////
            snake.eatApple();
        }
        for (int i = 0; i < board[0][0].getNumberFieldsY(); i++)
        {
            for (int j = 0; j < board[0][0].getNumberFieldsX(); j++)
            {
                window.draw(board[i][j]);
            }
        }
        Sleep(1.41*sleep/(0.7 * snake.getVectorSize()));
        window.display();
    }
}