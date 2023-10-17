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
	InitSprite(SPR_AI, 0, 0, Sprite_AiTiles, Sprite_AiTilesLen, Sprite_AiPal, Sprite_AiPalLen);
	InitSprite(SPR_ELLE, 0, 0, Sprite_ElleTiles, Sprite_ElleTilesLen, Sprite_EllePal, Sprite_EllePalLen);
	InitSprite(SPR_JAY, 0, 0, Sprite_JayTiles, Sprite_JayTilesLen, Sprite_JayPal, Sprite_JayPalLen);
	InitSprite(SPR_ESS, 0, 0, Sprite_EssTiles, Sprite_EssTilesLen, Sprite_EssPal, Sprite_EssPalLen);
	InitSprite(SPR_ZED, 0, 0, Sprite_ZedTiles, Sprite_ZedTilesLen, Sprite_ZedPal, Sprite_ZedPalLen);
	InitSprite(SPR_TEE, 0, 0, Sprite_TeeTiles, Sprite_TeeTilesLen, Sprite_TeePal, Sprite_TeePalLen);
	InitSprite(SPR_O, 0, 0, Sprite_OTiles, Sprite_OTilesLen, Sprite_OPal, Sprite_OPalLen);

	/*
	obj_set_attr(&oamArray[0], ATTR0_TALL, ATTR1_SIZE_8x32, SPR_AI);
	obj_set_attr(&oamArray[1], ATTR0_TALL, ATTR1_SIZE_16x32 | 8, SPR_ELLE);
	obj_set_attr(&oamArray[2], ATTR0_TALL, ATTR1_SIZE_16x32 | 24, SPR_JAY);
	obj_set_attr(&oamArray[3], ATTR0_WIDE, ATTR1_SIZE_32x16 | 40, SPR_ESS);
	obj_set_attr(&oamArray[4], ATTR0_WIDE, ATTR1_SIZE_32x16 | 72, SPR_ZED);
	obj_set_attr(&oamArray[5], ATTR0_WIDE, ATTR1_SIZE_32x16 | 104, SPR_TEE);
	oamCount += 6;
	*/
	Vec2 pos = {0,0};
	InitTetrimino(&oamArray[0], MINO_AI, pos);
	pos.x += 8;
	InitTetrimino(&oamArray[1], MINO_ELLE, pos);
	pos.x += 16;
	InitTetrimino(&oamArray[2], MINO_JAY, pos);
	pos.x += 16;
	InitTetrimino(&oamArray[3], MINO_ESS, pos);
	pos.x += 32;
	InitTetrimino(&oamArray[4], MINO_ZED, pos);
	pos.x += 32;
	InitTetrimino(&oamArray[5], MINO_TEE, pos);
	pos.x += 32;
	InitTetrimino(&oamArray[6], MINO_O, pos);
	
	oamCount += 7;

	REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;
	while(1){
		vid_vsync();
		
		oam_copy(oam_mem, oamArray, oamCount);
	}
}

void InitTetriminoAdd(int ID, Vec2 pos){
	/*switch(ID){
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
	tetriCount += 4;*/
}