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

// psfCounter - "Per Second Frame Counter"
int oamCount, psfCounter;

int main(){
	// Var Init
	oamCount = psfCounter = 0;

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

	int pc = 0;
	Vec2 pos = {0,0};

	REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;
	while(1){
		vid_vsync();
		key_poll();

		if(psfCounter == 60){
			InitTetriminoAdd(pc, pos);
			if(pc == 0)
				pc++;
			else
				pc *= 2;
			pos.x += 16;
			if(pc > MINO_ZED)
				pc = 0;
			if(pos.x > SCR_WID){
				pos.x = 0;
				pos.y += 16;
				if(pos.y > SCR_HGT)
					pos.y = 0;
			}
		}

		oam_copy(oam_mem, oamArray, oamCount);
		psfCounter++;
		if(psfCounter > 60)
			psfCounter = 0;
	}
}

void InitTetriminoAdd(int ID, Vec2 pos){
	InitTetrimino(&oamArray[oamCount], ID, pos);
	oamCount++;
	if(oamCount > OAM_MAX)
		oamCount = OAM_RESERVE + 1;
}