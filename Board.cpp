#include "Board.h"
#include "Tile.h"
#include <random>

void Board::setup()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Application");
    sf::RectangleShape board(sf::Vector2f(1000.0f, 1000.0f));
    board.setFillColor(sf::Color::Color(178, 190, 181));

    Tile pieces[10][10];
    for (int i = 0; i < 10; i++)
    {
        int xcoor = i * 100;
        for (int f = 0; f < 10; f++)
        {
            int ycoor = f * 100;
            pieces[i][f].setup(xcoor, ycoor);
        }
    }
    //pieces.setup(0, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //Action item that will update tile
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Color::Red;
                //pieces.setColor(sf::Color::Red);
                //clicking left mouse button updates tile transparency from 0 to 100;

            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                //clicking right mouse button sets a flag. don't know how to do this.


            }


            

            //random # generator
            //std::random_device dev;
            //std::mt19937 rng(dev());
            //std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 6); // distribution in range [1, 6]

            //std::cout << dist6(rng) << std::endl;

            //10 bombs, board is 10 X 10;

        }

        window.clear();
        window.draw(board);
        for (int i = 0; i < 10; i++)
        {
            for (int f = 0; f < 10; f++)
            {
                window.draw(pieces[i][f].getTile());
            }
        }
        window.display();
    }
}



//sf::Texture playerTexture;
//playerTexture.loadFromFile("");
//player.setTexture(&playerTexture);

