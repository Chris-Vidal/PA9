#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BombTile.h"

#include <random>

#include <stdlib.h> //rand(), srand()
#include <time.h> //time()

class Board
{
public:
    Board();
    Board(int numBombs);

    //~Board();
    void setup();

    void placeBombs(int count);
    void populateNumbers();

    bool isGameOver();

    void connectPieces();
    void leftClick(sf::RenderWindow& window, sf::RectangleShape& board);
    void rightClick(sf::RenderWindow& window, sf::RectangleShape& board);

    void revealBoard();

private:
    Tile* pieces[10][10];
    Tile mask[10][10];
};


