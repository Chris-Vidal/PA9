#include "Minesweeper.h"
#include "Board.h"


void Minesweeper::initialize()
{
	Board start(20);
	start.setup();
}

void Minesweeper::run()
{
	initialize();
}