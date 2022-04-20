#include "Tile.h"

Tile::Tile()
{
    //this->tile.setSize(sf::Vector2f(100.0f, 100.0f));
    this->setSize(sf::Vector2f(100.0f, 100.0f));
    mType = 'e'; // initially empty
    mClicked = false; // initially unclicked
    mBombNeighborCount = 0; // initially neighborless

    for (int i = 0; i < 8; i++) // initialize Border Tiles to nullptr
    {
        mBorderTile[i] = nullptr;
    }
}

void Tile::setup(const int& x, const int& y)
{
    /*tile.setFillColor(sf::Color::Color(178, 190, 181));
    tile.setOutlineColor(sf::Color::Black);
    tile.setOutlineThickness(1);
    tile.setPosition(x, y);*/
    setFillColor(sf::Color::White);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(1);
    setPosition(x, y);

    if (mType == 'e')
    {
        setFillColor(sf::Color::Color(178, 190, 181));
    }
    else if (mType == 'b')
    {
        setFillColor(sf::Color::Black);
    }
    else if (mType == 'n')
    {
        switch (borderBombCount()) // color depends on number of bombs next to Tile
        {
        case 1: setColor(sf::Color::Blue); break;
        case 2: setColor(sf::Color::Green); break;
        case 3: setColor(sf::Color::Yellow); break;
        case 4: setColor(sf::Color::Magenta); break;
        case 5: setColor(sf::Color::Cyan); break;
        case 6: setColor(sf::Color::Cyan); break;
        case 7: setColor(sf::Color::Cyan); break;
        case 8: setColor(sf::Color::Cyan); break;
        }
    }

}

sf::RectangleShape Tile::getTile() const
{
    return *this;
}

void Tile::setColor(sf::Color input)
{
    //this->tile.setFillColor(input);
    setFillColor(input);
}

// Author: NW
// Date: 4/18/2022
// Description: Check if tile is bomb
bool Tile::bombCheck()
{
    bool returnBool = false;

    if (this->mType == 'b')
    {
        returnBool = true;
    }

    return returnBool;
}

bool Tile::isGameOver()
{
    return mGameOver;
}

void Tile::gameOver()
{
    mGameOver = true;
}

// Author: NW
// Date: 4/18/2022
// Description: Count number of bombs bordering Tile
int Tile::borderBombCount()
{
    int count = 0;

    for (int i = 0; i < 8;i++)
    {
        if (mBorderTile[i] != nullptr &&
            mBorderTile[i]->mType == 'b')
        {
            count++;
        }
    }

    return count;
}

// Author: NW
// Date: 4/18/2022
// Description: Activate Tile with behavior dependent upon Tile type
void Tile::activate()
{
    /*for (int i = 0; i < 8; i++)
    {*/
        mClicked = true;
        if (mType == 'b')
        {
            // Game Over
        }
        else if (mType == 'e')
        {
            setFillColor(sf::Color::Color(100, 100, 100));

            // tile is blank, activate all surrounding tiles
            for (int j = 0; j < 8; j++)
            {
                if (mBorderTile[j] != nullptr && mBorderTile[j]->mClicked != true)
                {
                    mBorderTile[j]->activate();
                }
            }
        }
        else
        {
            // Tile is of number type

        }
    //}
}

// Author: NW
// Date: 4/19/2022
// Description: Get Tile type
char Tile::getType()
{
    return mType;
}

// Author: NW
// Date: 4/19/2022
// Description: Set Tile type
void Tile::setType(char type)
{
    mType = type;
}


// Author: NW
// Date: 4/19/2022
// Description: Plant bomb
void Tile::placeBomb()
{
    mType = 'b';
}


// Author: NW
// Date: 4/19/2022
// Description: Set number of bombs next to Tile
void Tile::setAdjacentBombCount()
{
    mBombNeighborCount = borderBombCount();
}

// Author: NW
// Date: 4/19/2022
// Description: Determine if Tile has been clicked
bool Tile::getClicked()
{
    return mClicked;
}

// Author: NW
// Date: 4/19/2022
// Description: Sets click condition of Tile
void Tile::setClicked(bool isClicked)
{
    mClicked = isClicked;
}

// Author: NW
// Date: 4/19/2022
// Description: Determine the number of neighboring bombs
int Tile::getNeighborBombs()
{
    return mBombNeighborCount;
}

// Author: NW
// Date: 4/19/2022
// Description: Set the number of neighboring bombs
void Tile::setNeighborBombs(int num) 
{
    mBombNeighborCount = num;
}




