#include "GameLogic.h"

int InitObject(OAMObject* objArr, int count, Vec2 pos, u16 col, u16 shp, u16 sz, u16 tile, u16 pri, u16 pal){
    if(count < OAM_MAX){
        objArr[count].pos = pos;
        objArr[count].colorMode = col;
        objArr[count].shape = shp;
        objArr[count].size = sz;
        objArr[count].tileIndex = tile;
        objArr[count].priority = pri;
        objArr[count].palette = pal;
        count++;
    }

    return count;
}

void UpdateObjects(OBJ_ATTR* oamArr, OAMObject* objArr, int count){
    for(int i = 0; i < count; i++){
        obj_set_attr(&oamArr[i],
            objArr[i].shape | objArr[i].colorMode | objArr[i].objMode | objArr[i].pos.y,
            objArr[i].size | objArr[i].vertFlip | objArr[i].hortFlip | objArr[i].pos.x,
            objArr[i].palette | objArr[i].priority | objArr[i].tileIndex);
    }
}

void InitTee(OAMObject* oA, int* oC, Tetrimino* tetArr, int* tetCount, Vec2 pos){
    for(int i = 0; i < 4; i++){
        oC = (int*)InitObject(oA, oC, pos, 0, 0, 0, SPR_TEE, 0, 0);
        pos.y += 8;
    }

    tetCount += 4;
}