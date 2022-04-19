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
    setFillColor(sf::Color::Color(178, 190, 181));
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
        setFillColor(sf::Color::Blue);
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
    for (int i = 0; i < 8; i++)
    {
        mClicked = true;
        if (mType == 'b')
        {
            // Game Over
        }
        else if (mType == 'e')
        {
            setFillColor(sf::Color::Red);

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
    }
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
