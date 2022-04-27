#include "Test.h"


void Test::testGetType() {
	
	cout << "Testing getType function:" << endl;
	// test 1:
	Board bTest1(100);

	if (bTest1.pieces[1][2]->getType() == 'b') {
		cout << "Test 1 success!" << endl;
		}

	// test 2:
	Board bTest2(0);

	if (bTest2.pieces[5][7]->getType() == 'e') {
		cout << "Test 2 success!" << endl;
	}

	// test 3:
	Board bTest3(99);

	int countNumTiles = 0;

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			if (bTest3.pieces[i][j]->getType() == 'n') {
				++countNumTiles;
			}
		}
	}

	if (countNumTiles == 1) {
		cout << "Test 3 success!" << endl;
	}
	else {
		cout << "Test 3 unsuccessful" << endl;
	}

}


// Author: MS
// Date: 4/21/2022
// Description: Test case to see if Board Constructor function works properly
void Test::testBoardConstructor() {
	
	cout << "Testing Board contructor:" << endl;

	// Test 1: Check the bomb tiles
	Board bTest1(25);

	int countBombs = 0;

	// count number of bombs
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			if (bTest1.pieces[i][j]->getType() == 'b') {
				++countBombs;
			}
		}
	}

	// checks to see if the correct number of bombs were placed
	if (countBombs == 25) {
		cout << "Test 1 success!" << endl;
	}
	else {
		cout << "Test 1 unsuccessful" << endl;
	}

	// Test 2: Check the number tiles
	Board bTest2(1);

	int countNumTiles = 0;

	// count number of number tiles
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			if (bTest2.pieces[i][j]->getType() == 'n') {
				++countNumTiles;
			}
		}
	}

	// checks to see if the correct number of bombs were placed
	// 8 = nonedge tile, 5 = edge & noncorner, 3 = corner tile
	if (countNumTiles == 8 || countNumTiles == 5 || countNumTiles == 3) {
		cout << "Test 2 success!" << endl;
	}
	else {
		cout << "Test 2 unsuccessful" << endl;
	}
}

// Author: MS
// Date: 4/21/2022
// Description: Test case to see if gameWon() function works properly
void Test::testgameOver() {

	cout << "Testing isGameOver function:" << endl;

	Board bTest(100);

	bool success = false;


	// no tiles are clicked
	// call the isGameOver function
	success = bTest.isGameOver();

	// feedback
	if (success) {
		cout << "Test 1 failed" << endl;
	}
	else {
		cout << "Test 1 success (Game not over)" << endl;
	}


	// set every tile that is not a bomb to clicked
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			if (bTest.pieces[i][j]->getType() != 'b') {
				bTest.pieces[i][j]->setClicked(true);
				bTest.pieces[i][j]->activate();
			}
		}
	}

	// call the isGameOver function
	success = bTest.isGameOver();

	// feedback
	if (success) {
		cout << "Test 2 failed" << endl;
	}
	else {
		cout << "Test 2 success (Game not over)" << endl;
	}

		// set every tile that is a bomb to clicked
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			if (bTest.pieces[i][j]->getType() == 'b') {
				bTest.pieces[i][j]->setClicked(true);
				bTest.pieces[i][j]->activate();
			}
		}
	}

	// call the isGameOver function
	success = bTest.isGameOver();

	// feedback
	if (success) {
		cout << "Test 3 success (game over)" << endl;
	}
	else {
		cout << "Test 2 failed" << endl;
	}


	// set every tile to clicked
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {
			bTest.pieces[i][j]->setClicked(true);
			bTest.pieces[i][j]->activate();

		}
	}

	// call the isGameOver function
	success = bTest.isGameOver();

	// feedback
	if (success) {
		cout << "Test 4 success (game over)" << endl;
	}
	else {
		cout << "Test 4 unsuccessful" << endl;
	}


}

// Author: MS
// Date: 4/21/2022
// Description: Test case to see if gameWon() function works properly
void Test::testgameWon() {

	cout << "Testing gameWon function:" << endl;


	Board bTest(3);

	bool success = false;


	// no tiles are clicked
	// call the gameWon function
	success = bTest.gameWon();

	// feedback
	if (success) {
		cout << "Test 1 game won" << endl;
	}
	else {
		cout << "Test 1 success not all the tiles are clicked (game not won)" << endl;
	}


	// set every tile that is not a bomb to clicked
    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 10; j++) {
			
            if (bTest.pieces[i][j]->getType() != 'b') {
				bTest.pieces[i][j]->setClicked(true);
				}
        }
    }

	// call the gameWon function
	success = bTest.gameWon();

	// feedback
	if (success) {
		cout << "Test 2 success (game won)" << endl;
	}
	else {
		cout << "Test 2 not all the tiles are clicked (game not won)" << endl;
	}


	// set every tile to clicked
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			bTest.pieces[i][j]->setClicked(true);
		}
	}

	// call the gameWon function
	success = bTest.gameWon();

	// feedback
	if (success) {
		cout << "Test 3 game won" << endl;
	}
	else {
		cout << "Test 3 success, bomb was clicked (game not won)" << endl;
	}
}

// Author: MS
// Date: 4/21/2022
// Description: Test case to see if BorderBombCount() function works properly
void Test::testBorderBombCount() {
	
	cout << "Testing borderBombCount function:" << endl;
	
	// Test 1: 1 bomb, should return one bomb near it
	Board bTest1(1);
	int returnedCount = 0;

	// gets the number of bombs near number tile
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			if (bTest1.pieces[i][j]->getType() == 'n') {
				returnedCount = bTest1.pieces[i][j]->borderBombCount();
			}
		}
	}

	// feedback
	if (returnedCount == 1) {
		cout << "Test 1 success!" << endl;
	}
	else {
		cout << "Test 1 unsuccessful" << endl;
	}

	// Test 2: 100 bomb, should return zero near
	Board bTest2(99);
	returnedCount = 0;

	// gets the number of bombs near number tile
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			if (bTest2.pieces[i][j]->getType() == 'n') {
				returnedCount = bTest2.pieces[i][j]->borderBombCount();
			}
		}
	}

	// feedback
	// 8 = nonedge tile, 5 = edge & noncorner, 3 = corner tile
	if (returnedCount == 8 || returnedCount == 5 || returnedCount == 3) {
		cout << "Test 2 success!" << endl;
	}
	else {
		cout << "Test 2 unsuccessful" << endl;
	}

	// Test 3: 100 bomb, should return zero near
	Board bTest3(100);
	returnedCount = 0;

	// gets the number of bombs near number tile
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			if (bTest3.pieces[i][j]->getType() == 'n') {
				returnedCount = bTest3.pieces[i][j]->borderBombCount();
			}
		}
	}

	// feedback
	if (returnedCount == 0) {
		cout << "Test 3 success!" << endl;
	}
	else {
		cout << "Test 3 unsuccessful" << endl;
	}


}
