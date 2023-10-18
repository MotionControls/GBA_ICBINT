#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <tonc.h>

#include "Sprites.h"
#include "SelfDefs.h"

#define GRID_WID    10
#define GRID_HGT    24
#define GRID_CUTOFF 4       // How far from the top a tetrimino has to be placed to gameover.
#define OAM_MAX     128     // Max amount of objects allowed.
#define OAM_RESERVE 8       // Reserved for stuff like UI.

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

typedef struct{
    int minoType;   // Which tetrimino it is.
    int minos[4];   // All minos making up the tetrimino.
    int rot;        // 0 = 0 ; 1 = 90 ; 2 = 180 ; 3 = 270
    Vec2 pos;       // Pos of the origin.
}Tetrimino;

/*  Mino w/ Origins
            [ ]                                 
    [ ]     [ ]     [ ]        [ ]   [ ]        
    [ ]     [x]     [ ]     [x][ ]   [ ][x]        [ ]
    [x][ ]  [ ]  [ ][x]     [ ]         [ ]     [ ][x][ ]
*/  

int InitObject(OAMObject* objArr, int count, Vec2 pos, u16 col, u16 shp, u16 sz, u16 tile, u16 pri, u16 pal);
void UpdateObjects(OBJ_ATTR* oamArr, OAMObject* objArr, int count);

void InitTetrimino(OBJ_ATTR* obj, int ID, Vec2 pos);
void RemoveTetrimino(OBJ_ATTR* obj);

void InitTee(OAMObject* objArr, int objCount, Vec2 pos);
void InitEss(OAMObject* objArr, int objCount, Vec2 pos);
void InitO(OAMObject* objArr, int objCount, Vec2 pos);
void InitAi(OAMObject* objArr, int objCount, Vec2 pos);
void InitJay(OAMObject* objArr, int objCount, Vec2 pos);
void InitElle(OAMObject* objArr, int objCount, Vec2 pos);
void InitZed(OAMObject* objArr, int objCount, Vec2 pos);

#endif