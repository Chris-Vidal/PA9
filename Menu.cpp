#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("sansation.ttf"))
	{
		cout << "Font failed" << endl;
	}

	//play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 200);
	//How to Play
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("How To Play");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 300);
	//Exit
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Quit");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 400);
	//Exit
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Quit");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 400);

	menuSelected = -1;
}

//drawn menu
void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < OPTIONS; i++)
	{
		window.draw(mainMenu[i]);
	}
}

//move up
void Menu::moveUp()
{
	if (menuSelected - 1 >= 0)
	{
		mainMenu[menuSelected].setFillColor(Color::White);
		menuSelected--;
		if (menuSelected == -1)
		{
			menuSelected = 2;
		}
		mainMenu[menuSelected].setFillColor(Color::Blue);
	}
}
//move down
void Menu::moveDown()
{
	if (menuSelected + 1 <= OPTIONS)
	{
		mainMenu[menuSelected].setFillColor(Color::White);
		menuSelected++;
		if (menuSelected == 3)
		{
			menuSelected = 2; //interesting. If set to 0, it rolls to the top. Set to 3 and it messes up the color.
		}
		mainMenu[menuSelected].setFillColor(Color::Blue);
	}
}

