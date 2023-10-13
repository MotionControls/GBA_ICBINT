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

int InitSprite(int spriteBank, int size, u16 palStepSize, const u16* tiles, int tilesLen, const u16* palette, int paletteLen);
void InitBackground(const u16*, int, const u16*, int, const u16*, int);

#endif