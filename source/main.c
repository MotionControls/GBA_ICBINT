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

	// Init Resources
	oam_init(oamArray, OAM_MAX);
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_Mino1Tiles, Sprite_Mino1TilesLen, Sprite_Mino1Pal, Sprite_Mino1PalLen);
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_Mino2Tiles, Sprite_Mino2TilesLen, Sprite_Mino2Pal, Sprite_Mino2PalLen);
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_Mino3Tiles, Sprite_Mino3TilesLen, Sprite_Mino3Pal, Sprite_Mino3PalLen);
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_Mino4Tiles, Sprite_Mino4TilesLen, Sprite_Mino4Pal, Sprite_Mino4PalLen);
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_Mino5Tiles, Sprite_Mino5TilesLen, Sprite_Mino5Pal, Sprite_Mino5PalLen);
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_Mino6Tiles, Sprite_Mino6TilesLen, Sprite_Mino6Pal, Sprite_Mino6PalLen);

	Vec2 pos = {0,0};
	do{
		oamCount = InitObject(objArray, oamCount, pos, 0, 0, 0, oamCount, 0, 0);
		pos.x += 8;
	}while(oamCount < 6);

	REG_DISPCNT = DCNT_OBJ | DCNT_BG0 | DCNT_BG1;
	while(1){
		vid_vsync();
		
		UpdateObjects(oamArray, objArray, oamCount);

		oam_copy(oam_mem, oamArray, oamCount);
	}
}