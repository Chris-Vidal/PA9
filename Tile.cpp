#include "Tile.h"


Tile::Tile()
{
    this->tile.setSize(sf::Vector2f(100.0f, 100.0f));
}

void Tile::setup(const int& x, const int& y)
{
    tile.setFillColor(sf::Color::Color(178, 190, 181));
    tile.setOutlineColor(sf::Color::Black);
    tile.setOutlineThickness(1);
    tile.setPosition(x, y);

}

sf::RectangleShape Tile::getTile() const
{
    return tile;
}

void Tile::setColor(sf::Color input)
{
    this->tile.setFillColor(input);
}
