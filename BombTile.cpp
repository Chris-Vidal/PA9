#include "BombTile.h"

// Author: NW
// Date: 4/19/2022
// Description: End the game upon activation
void BombTile::activate()
{
	gameOver();
}

// Author: NW
// Date: 4/19/2022
// Description: Construct a BombTile with attributes from copied Tile
BombTile::BombTile(Tile& tile)
{
	setType(tile.getType());
	setClicked(tile.getClicked());
	setNeighborBombs(tile.getNeighborBombs());
	
	for (int i = 0; i < 8; i++)
	{
		mBorderTile[i] = tile.mBorderTile[i];
	}
}
