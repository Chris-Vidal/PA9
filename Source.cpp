#include <SFML/Graphics.hpp>
#include "Minesweeper.h"
#include "Test.h"

int main()
{
	Minesweeper app;
	Test test;
	
	// test cases
	cout << "5 Test Cases:" << endl;
	test.testGetType();
	test.testBoardConstructor();
	test.testgameOver();
	test.testgameWon();
	test.testBorderBombCount();

	system("pause");
	system("cls");

	// application
	cout << "Use arrow keys and press enter to select menu options" << endl;
	app.run();

	return 0;
}
