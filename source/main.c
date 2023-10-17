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

	// Mino Sprites
	//memcpy16(&tile_mem[4][0], Sprite_AiTiles, Sprite_AiTilesLen);
	//memcpy16(pal_obj_mem, Sprite_AiPal, Sprite_AiPalLen);
	InitSprite(SPR_AI, Sprite_AiTiles, Sprite_AiTilesLen, Sprite_AiPal, Sprite_AiPalLen);
	InitSprite(SPR_ELLE, Sprite_ElleTiles, Sprite_ElleTilesLen, Sprite_EllePal, Sprite_EllePalLen);
	InitSprite(SPR_JAY, Sprite_JayTiles, Sprite_JayTilesLen, Sprite_JayPal, Sprite_JayPalLen);
	InitSprite(SPR_ESS, Sprite_EssTiles, Sprite_EssTilesLen, Sprite_EssPal, Sprite_EssPalLen);
	InitSprite(SPR_ZED, Sprite_ZedTiles, Sprite_ZedTilesLen, Sprite_ZedPal, Sprite_ZedPalLen);
	InitSprite(SPR_TEE, Sprite_TeeTiles, Sprite_TeeTilesLen, Sprite_TeePal, Sprite_TeePalLen);
	InitSprite(SPR_O, Sprite_OTiles, Sprite_OTilesLen, Sprite_OPal, Sprite_OPalLen);

	Vec2 pos = {0,0};
	InitTetriminoAdd(MINO_AI, pos);
	pos.x += 8;
	InitTetriminoAdd(MINO_ELLE, pos);
	pos.x += 16;
	InitTetriminoAdd(MINO_JAY, pos);
	pos.x += 16;
	InitTetriminoAdd(MINO_ESS, pos);
	pos.x += 32;
	InitTetriminoAdd(MINO_ZED, pos);
	pos.x += 32;
	InitTetriminoAdd(MINO_TEE, pos);
	pos.x += 32;
	InitTetriminoAdd(MINO_O, pos);
	
	REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;
	while(1){
		vid_vsync();
		
		oam_copy(oam_mem, oamArray, oamCount);
	}
}

void InitTetriminoAdd(int ID, Vec2 pos){
	InitTetrimino(&oamArray[oamCount], ID, pos);
	oamCount++;
}