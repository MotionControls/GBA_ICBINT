#ifndef LOGIC_H
#define LOGIC_H

#include "tonc.h"

#define OAM_MAX 128         // Max amount of objects allowed.

typedef struct{             // Representation of OAM objects.
    u16 x, y;
    u16 objMode;
    u16 colorMode;
    u16 shape, size;
    u16 hortFlip, vertFlip;
    u16 tileIndex, priority;
    u16 palette;
}OAMObject;

void UpdateObjects(OBJ_ATTR*,OAMObject*,int);

#endif