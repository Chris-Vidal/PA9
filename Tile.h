#pragma once
#include <SFML/Graphics.hpp>


class Tile
{
private:
	sf::RectangleShape tile;

public:
	Tile();
	//~Tile();
	void setup(const int& x = 0, const int& y =0);
	sf::RectangleShape getTile() const;
	void setColor(sf::Color input);
};

