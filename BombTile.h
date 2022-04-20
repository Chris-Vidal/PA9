#include "Tile.h"

class BombTile : public Tile
{
public:
	void activate();
	BombTile(Tile& tile);
};