#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <tonc.h>

#include "SelfDefs.h"
#include "GameLogic.h"
#include "Sprites.h"

OBJ_ATTR oamArray[OAM_MAX];		// OAM Buffer
OAMObject objArray[OAM_MAX];

int main(){
	// Var Init
	int oamCount = 0;
	int curSpriteID = 0;
	//int curCharBlock = 4;
	int curScrBlock = 0;

	// Init
	oam_init(oamArray, OAM_MAX);
	
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_TestTiles, Sprite_TestTilesLen, Sprite_TestPal, Sprite_TestPalLen);
	Vec2 pos = {10,15};
	oamCount = InitObject(objArray, oamCount, pos, 0, 0, 0, 0, 0, 0);

	curSpriteID = InitSprite(curSpriteID, 8, Sprite_TestPalLen, Sprite_Test2Tiles, Sprite_Test2TilesLen, Sprite_Test2Pal, Sprite_Test2PalLen);
	pos.x = pos.y = 0;
	oamCount = InitObject(objArray, oamCount, pos, 0, 0, 0, 1, 0, 0);

	REG_DISPCNT = DCNT_OBJ | DCNT_BG0 | DCNT_BG1;
	while(1){
		vid_vsync();
		
		UpdateObjects(oamArray, objArray, oamCount);

		oam_copy(oam_mem, oamArray, oamCount);
	}
}