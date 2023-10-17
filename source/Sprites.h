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

// Sizes assume the Tetriminos are right-side up.
#define SPR_AI_WID     8
#define SPR_AI_HGT     32

#define SPR_ESS_WID     24
#define SPR_ESS_HGT     16

#define SPR_ZED_WID     24
#define SPR_ZED_HGT     16

#define SPR_TEE_WID     24
#define SPR_TEE_HGT     16

#define SPR_ELLE_WID    16
#define SPR_ELLE_HGT    24

#define SPR_JAY_WID     16
#define SPR_JAY_HGT     24

#define SPR_O_WID       16
#define SPR_O_HGT       16

void InitSprite(int spriteBank, const u16* tiles, int tilesLen, const u16* palette, int paletteLen);
void InitBackground(const u16*, int, const u16*, int, const u16*, int);

#endif