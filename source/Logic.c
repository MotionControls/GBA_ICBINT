#include "Logic.h"

void UpdateObjects(OBJ_ATTR* oamArr, OAMObject* objArr, int count){
    for(int i = 0; i < count; i++){
        obj_set_attr(&oamArr[i],
            objArr[i].shape | objArr[i].colorMode | objArr[i].objMode | objArr[i].y,
            objArr[i].size | objArr[i].vertFlip | objArr[i].hortFlip | objArr[i].x,
            objArr[i].palette | objArr[i].priority | objArr[i].tileIndex);
    }
}