#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define OPTIONS 3

class Menu
{
private:
	int menuSelected;
	Font font;
	Text mainMenu[OPTIONS];

public:
	Menu(float width, float height);

	void draw(RenderWindow& window);
	void moveUp();
	void moveDown();

	int mainMenuPressed()
	{
		return menuSelected;
	}
	//~Menu();
};

