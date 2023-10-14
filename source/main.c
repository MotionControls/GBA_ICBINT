#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <tonc.h>

#include "SelfDefs.h"
#include "GameLogic.h"
#include "Sprites.h"

void InitTetriminoAdd(int ID, Vec2 pos);

OBJ_ATTR oamArray[OAM_MAX];			// OAM Buffer
OAMObject objArray[OAM_MAX];
Tetrimino tetriminoArray[OAM_MAX];

int oamCount, tetriCount, curSpriteID;

int main(){
	// Var Init
	oamCount = 0;
	tetriCount = 0;
	curSpriteID = 0;
	//int curScrBlock = 0;

	// Init Resources
	oam_init(oamArray, OAM_MAX);
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_Mino1Tiles, Sprite_Mino1TilesLen, Sprite_Mino1Pal, Sprite_Mino1PalLen);
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_Mino2Tiles, Sprite_Mino2TilesLen, Sprite_Mino2Pal, Sprite_Mino2PalLen);
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_Mino3Tiles, Sprite_Mino3TilesLen, Sprite_Mino3Pal, Sprite_Mino3PalLen);
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_Mino4Tiles, Sprite_Mino4TilesLen, Sprite_Mino4Pal, Sprite_Mino4PalLen);
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_Mino5Tiles, Sprite_Mino5TilesLen, Sprite_Mino5Pal, Sprite_Mino5PalLen);
	curSpriteID = InitSprite(curSpriteID, 8, 0, Sprite_Mino6Tiles, Sprite_Mino6TilesLen, Sprite_Mino6Pal, Sprite_Mino6PalLen);

	int temp = 0;
	Vec2 pos = {0, 0};
	do{
		InitTetriminoAdd(temp, pos);
		pos.x += 32;
		if(temp == 0)
			temp += 1;
		else
			temp *= 2;
	}while(temp <= MINO_ZED);
	//oamCount = InitTee(objArray, oamCount, pos);

	REG_DISPCNT = DCNT_OBJ | DCNT_BG0 | DCNT_BG1;
	while(1){
		vid_vsync();
		
		UpdateObjects(oamArray, objArray, oamCount);

		oam_copy(oam_mem, oamArray, oamCount);
	}
}

void InitTetriminoAdd(int ID, Vec2 pos){
	switch(ID){
		case MINO_TEE:
			InitTee(objArray, oamCount, pos);
			break;
		case MINO_ESS:
			InitEss(objArray, oamCount, pos);
			break;
		case MINO_O:
			InitO(objArray, oamCount, pos);
			break;
		case MINO_AI:
			InitAi(objArray, oamCount, pos);
			break;
		case MINO_JAY:
			InitJay(objArray, oamCount, pos);
			break;
		case MINO_ELLE:
			InitElle(objArray, oamCount, pos);
			break;
		case MINO_ZED:
			InitZed(objArray, oamCount, pos);
			break;
	}

	oamCount += 4;
	tetriCount += 4;
}