#ifndef SPRITES_H
#define SPRITES_H

#include <tonc.h>

#include "sprites/Sprite_Test.h"
#include "sprites/Sprite_Test2.h"
#include "sprites/Sprite_Mino1.h"
#include "sprites/Sprite_Mino2.h"
#include "sprites/Sprite_Mino3.h"
#include "sprites/Sprite_Mino4.h"
#include "sprites/Sprite_Mino5.h"
#include "sprites/Sprite_Mino6.h"

#include "sprites/Sprite_Ai.h"
#include "sprites/Sprite_Elle.h"
#include "sprites/Sprite_Jay.h"
#include "sprites/Sprite_Ess.h"
#include "sprites/Sprite_Zed.h"
#include "sprites/Sprite_Tee.h"
#include "sprites/Sprite_O.h"

// Sprite IDs for Tetriminoes.
#define SPR_TEE     SPR_ZED+8   // T
#define SPR_ESS     SPR_JAY+8   // S
#define SPR_O       SPR_TEE+8   // O
#define SPR_AI      0           // I
#define SPR_JAY     SPR_ELLE+8  // J
#define SPR_ELLE    SPR_AI+4    // L
#define SPR_ZED     SPR_ESS+8   // Z

int InitSprite(int spriteBank, int perTileSize, int tileCount, const u16* tiles, int tilesLen, const u16* palette, int paletteLen);
void InitBackground(const u16*, int, const u16*, int, const u16*, int);

#endif