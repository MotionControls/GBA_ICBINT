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

// Sprite IDs for Tetriminoes.
#define SPR_TEE     0   // T
#define SPR_ESS     5   // S
#define SPR_O       2   // O
#define SPR_AI      1   // I
#define SPR_JAY     4   // J
#define SPR_ELLE    5   // L
#define SPR_ZED     4   // Z

int InitSprite(int spriteBank, int size, u16 palStepSize, const u16* tiles, int tilesLen, const u16* palette, int paletteLen);
void InitBackground(const u16*, int, const u16*, int, const u16*, int);

#endif