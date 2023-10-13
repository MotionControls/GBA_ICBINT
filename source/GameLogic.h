#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "tonc.h"

#define OAM_MAX 128         // Max amount of objects allowed.

typedef struct{
    u16 x, y;
}Vec2;

typedef struct{             // Representation of OAM objects.
    Vec2 pos;
    u16 objMode;
    u16 colorMode;
    u16 shape, size;
    u16 hortFlip, vertFlip;
    u16 tileIndex, priority;
    u16 palette;
}OAMObject;

int InitObject(OAMObject* objArr, int count, Vec2 pos, u16 col, u16 shp, u16 sz, u16 tile, u16 pri, u16 pal);
void UpdateObjects(OBJ_ATTR* oamArr, OAMObject* objArr, int count);

#endif