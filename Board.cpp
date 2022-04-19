#include "Board.h"

// Author: NW
// Date: 4/19/2022
// Description: Construct Blank Board
Board::Board()
{
    for (int i = 0; i < 10; i++)
    {
        int xcoor = i * 100;
        for (int f = 0; f < 10; f++)
        {
            int ycoor = f * 100;
            pieces[i][f].setup(xcoor, ycoor);
        }
    }
}

// Author: NW
// Date: 4/19/2022
// Description: Construct Board, plant bombs, assign Tile type, and connect neighboring Tiles
Board::Board(int numBombs)
{
    placeBombs(numBombs);
    connectPieces();
    populateNumbers();

    for (int i = 0; i < 10; i++)
    {
        int xcoor = i * 100;
        for (int f = 0; f < 10; f++)
        {
            int ycoor = f * 100;
            pieces[i][f].setup(xcoor, ycoor);
        }
    }
}

// Author: NW
// Date: 4/19/2022
// Description: Determine which Tile to activate based on mouse position
void Board::leftClick(sf::RenderWindow& window, sf::RectangleShape& board)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (sf::Mouse::getPosition(window).x > pieces[i][j].getPosition().x &&
                ((sf::Mouse::getPosition(window).x > 900 && i == 9) || sf::Mouse::getPosition(window).x < pieces[i + 1][j].getPosition().x) &&
                sf::Mouse::getPosition(window).y > pieces[i][j].getPosition().y &&
                ((sf::Mouse::getPosition(window).y > 900 && j == 9) || sf::Mouse::getPosition(window).y < pieces[i][j + 1].getPosition().y))
            {
                pieces[i][j].activate();
            }
        }
    }
}

void Board::setup()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Application");
    sf::RectangleShape board(sf::Vector2f(1000.0f, 1000.0f));
    board.setFillColor(sf::Color::Color(178, 190, 181));

    /*Tile pieces[10][10];
    for (int i = 0; i < 10; i++)
    {
        int xcoor = i * 100;
        for (int f = 0; f < 10; f++)
        {
            int ycoor = f * 100;
            pieces[i][f].setup(xcoor, ycoor);
        }
    }*/
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
                leftClick(window, board);

                //sf::Color::Red;

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
        //window.draw(board);
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


// Author: NW
// Date: 4/19/2022
// Description: Randomly place bombs on board
void Board::placeBombs(int count)
{
    srand((unsigned int)time(NULL)); // call only once

    int randX = 0;
    int randY = 0;

    do
    {
        randX = rand() % 10;
        randY = rand() % 10;

        if (pieces[randX][randY].getType() == 'e')
        {
            pieces[randX][randY].placeBomb();
            count--;
        }
    } while (count != 0);
}

// Author: NW
// Date: 4/19/2022
// Description: Populates number tiles on Board relevant to bomb placement
void Board::populateNumbers()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            pieces[i][j].setAdjacentBombCount();
            if (pieces[i][j].borderBombCount() != 0)
            {
                if (pieces[i][j].getType() != 'b')
                {
                    pieces[i][j].setType('n');
                }
            }
        }
    }
}

// Author: NW
// Date: 4/19/2022
// Description: Connects each Tile to its neigboring 3 - 8 Tiles
void Board::connectPieces()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 0 && j == 0) // upper-left corner
            {
                pieces[i][j].mBorderTile[3] = &pieces[i + 1][j]; // center-right
                pieces[i][j].mBorderTile[4] = &pieces[i + 1][j + 1]; // lower-right
                pieces[i][j].mBorderTile[5] = &pieces[i][j + 1]; // center-lower
            }
            else if (i == 0 && j == 9) // lower-left corner
            {
                pieces[i][j].mBorderTile[1] = &pieces[i][j - 1]; // center-upper
                pieces[i][j].mBorderTile[2] = &pieces[i + 1][j - 1]; // upper-right
                pieces[i][j].mBorderTile[3] = &pieces[i + 1][j]; // center-right
            }
            else if (i == 9 && j == 0) // upper right corner
            {
                pieces[i][j].mBorderTile[7] = &pieces[i - 1][j]; // center-left
                pieces[i][j].mBorderTile[6] = &pieces[i - 1][j + 1]; // lower-left
                pieces[i][j].mBorderTile[5] = &pieces[i][j + 1]; // center-lower
            }
            else if (i == 9 && j == 9) // lower right corner
            {
                pieces[i][j].mBorderTile[0] = &pieces[i - 1][j - 1]; // upper-left
                pieces[i][j].mBorderTile[1] = &pieces[i][j - 1]; // center-upper
                pieces[i][j].mBorderTile[7] = &pieces[i - 1][j]; // center-left
            }
            else if (i == 0) // left border non-corner
            {
                pieces[i][j].mBorderTile[1] = &pieces[i][j - 1]; // center-upper
                pieces[i][j].mBorderTile[2] = &pieces[i + 1][j - 1]; // upper-right
                pieces[i][j].mBorderTile[3] = &pieces[i + 1][j]; // center-right
                pieces[i][j].mBorderTile[4] = &pieces[i + 1][j + 1]; // lower-right
                pieces[i][j].mBorderTile[5] = &pieces[i][j + 1]; // center-lower
            }
            else if (i == 9) // right border non-corner
            {
                pieces[i][j].mBorderTile[0] = &pieces[i - 1][j - 1]; // upper-left
                pieces[i][j].mBorderTile[1] = &pieces[i][j - 1]; // center-upper
                pieces[i][j].mBorderTile[5] = &pieces[i][j + 1]; // center-lower
                pieces[i][j].mBorderTile[6] = &pieces[i - 1][j + 1]; // lower-left
                pieces[i][j].mBorderTile[7] = &pieces[i - 1][j]; // center-left
            }
            else if (j == 0) // upper border non-corner
            {
                pieces[i][j].mBorderTile[3] = &pieces[i + 1][j]; // center-right
                pieces[i][j].mBorderTile[4] = &pieces[i + 1][j + 1]; // lower-right
                pieces[i][j].mBorderTile[5] = &pieces[i][j + 1]; // center-lower
                pieces[i][j].mBorderTile[6] = &pieces[i - 1][j + 1]; // lower-left
                pieces[i][j].mBorderTile[7] = &pieces[i - 1][j]; // center-left
            }
            else if (j == 9) // lower border non-corner
            {
                pieces[i][j].mBorderTile[0] = &pieces[i - 1][j - 1]; // upper-left
                pieces[i][j].mBorderTile[1] = &pieces[i][j - 1]; // center-upper
                pieces[i][j].mBorderTile[2] = &pieces[i + 1][j - 1]; // upper-right
                pieces[i][j].mBorderTile[3] = &pieces[i + 1][j]; // center-right
                pieces[i][j].mBorderTile[7] = &pieces[i - 1][j]; // center-left
            }
            else // non-border
            {
                pieces[i][j].mBorderTile[0] = &pieces[i - 1][j - 1]; // upper-left
                pieces[i][j].mBorderTile[1] = &pieces[i][j - 1]; // center-upper
                pieces[i][j].mBorderTile[2] = &pieces[i + 1][j - 1]; // upper-right
                pieces[i][j].mBorderTile[3] = &pieces[i + 1][j]; // center-right
                pieces[i][j].mBorderTile[4] = &pieces[i + 1][j + 1]; // lower-right
                pieces[i][j].mBorderTile[5] = &pieces[i][j + 1]; // center-lower
                pieces[i][j].mBorderTile[6] = &pieces[i - 1][j + 1]; // lower-left
                pieces[i][j].mBorderTile[7] = &pieces[i - 1][j]; // center-left
            }
        }
    }
}