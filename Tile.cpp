#include "Tile.h"

Tile::Tile()
{
    //this->tile.setSize(sf::Vector2f(100.0f, 100.0f));
    this->setSize(sf::Vector2f(100.0f, 100.0f));
    mType = 'e'; // initially empty
    mClicked = false; // initially unclicked
    mBombNeighborCount = 0; // initially neighborless
    mGameOver = false;


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
        case 1: //setColor(sf::Color::Blue); break;
        {
            setColor(sf::Color::Cyan);
            tileText.loadFromFile("1.png");
            setTexture(&tileText);
            break;
        }

        case 2:
        {
            setColor(sf::Color::Yellow);
            tileText.loadFromFile("2.png");
            setTexture(&tileText);
            break;
        }
        case 3:// setColor(sf::Color::Yellow); break;
        {
            setColor(sf::Color::Green);
            tileText.loadFromFile("3.png");
            setTexture(&tileText);
            break;
        }

        case 4:// setColor(sf::Color::Magenta); break;
        {
            tileText.loadFromFile("4.png");
            setTexture(&tileText);
            break;
        }
        case 5:
        {
            tileText.loadFromFile("5.png");
            setTexture(&tileText);
            break;
        }
        case 6:
        {
            tileText.loadFromFile("6.png");
            setTexture(&tileText);
            break;
        }
        case 7: 
        {
            tileText.loadFromFile("7.png");
            setTexture(&tileText);
            break;
        }
        case 8:
        {
            tileText.loadFromFile("8.png");
            setTexture(&tileText);
            break;
        }
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

bool Tile::flag(bool check, bool input)
{
    if (check && input)
    {
        //tileText.~Texture();
        setTexture(NULL);
        return false;
    }
    else
    {
        tileText.loadFromFile("flag.png");
        setTexture(&tileText);
        return true;
    }
    return check;
}
