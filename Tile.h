#pragma once
#include <SFML/Graphics.hpp>


class Tile : public sf::RectangleShape
{
private:
	//sf::RectangleShape tile;
	char mType;
	bool mClicked;
	int mBombNeighborCount;
	bool mGameOver;
	


public:
	Tile();
	//~Tile();
	void setup(const int& x = 0, const int& y = 0);
	sf::RectangleShape getTile() const;
	void setColor(sf::Color input);

	bool bombCheck();
	int borderBombCount();
	virtual void activate();
	char getType();
	void placeBomb();
	void setAdjacentBombCount();
	void setType(char type);

	Tile* mBorderTile[8];
	bool isGameOver();
	void gameOver();
	bool getClicked();
	void setClicked(bool isClicked);
	int getNeighborBombs();
	void setNeighborBombs(int num);

};

