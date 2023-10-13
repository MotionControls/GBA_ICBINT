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