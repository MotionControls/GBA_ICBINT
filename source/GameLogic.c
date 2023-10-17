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

void InitTetrimino(OBJ_ATTR* obj, int ID, Vec2 pos){
    u16 shape = 0;
    u16 size = 0;
    u16 tiles = 0;

    switch(ID){
        case MINO_AI:
            shape = ATTR0_TALL;
            size = ATTR1_SIZE_8x32;
            tiles = SPR_AI;
            break;
        case MINO_ELLE:
            shape = ATTR0_TALL;
            size = ATTR1_SIZE_16x32;
            tiles = SPR_ELLE;
            break;
        case MINO_JAY:
            shape = ATTR0_TALL;
            size = ATTR1_SIZE_16x32;
            tiles = SPR_JAY;
            break;
        case MINO_ESS:
            shape = ATTR0_WIDE;
            size = ATTR1_SIZE_32x16;
            tiles = SPR_ESS;
            break;
        case MINO_ZED:
            shape = ATTR0_WIDE;
            size = ATTR1_SIZE_32x16;
            tiles = SPR_ZED;
            break;
        case MINO_TEE:
            shape = ATTR0_WIDE;
            size = ATTR1_SIZE_32x16;
            tiles = SPR_TEE;
            break;
        case MINO_O:
            size = ATTR1_SIZE_16x16;
            tiles = SPR_O;
            break;
    }

    obj_set_attr(obj, shape | pos.y, size | pos.x, tiles);
}

/*
void InitTee(OAMObject* oA, int oC, Vec2 pos){
    pos.y += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_TEE, 0, 0);
    pos.x += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_TEE, 0, 0);
    pos.x += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_TEE, 0, 0);
    pos.x -= 8;
    pos.y -= 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_TEE, 0, 0);

    //return oC;
}

void InitEss(OAMObject* oA, int oC, Vec2 pos){
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_ESS, 0, 0);
    pos.y += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_ESS, 0, 0);
    pos.x += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_ESS, 0, 0);
    pos.y += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_ESS, 0, 0);

    //return oC;
}

void InitO(OAMObject* oA, int oC, Vec2 pos){
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_O, 0, 0);
    pos.y += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_O, 0, 0);
    pos.y -= 8;
    pos.x += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_O, 0, 0);
    pos.y += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_O, 0, 0);

    //return oC;
}

void InitAi(OAMObject* oA, int oC, Vec2 pos){
    for(int i = 0; i < 4; i++){
        oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_AI, 0, 0);
        pos.y += 8;
    }

    //return oC;
}

void InitJay(OAMObject* oA, int oC, Vec2 pos){
    pos.x += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_JAY, 0, 0);
    pos.y += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_JAY, 0, 0);
    pos.y += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_JAY, 0, 0);
    pos.x -= 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_JAY, 0, 0);

    //return oC;
}

void InitElle(OAMObject* oA, int oC, Vec2 pos){
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_ELLE, 0, 0);
    pos.y += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_ELLE, 0, 0);
    pos.y += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_ELLE, 0, 0);
    pos.x += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_ELLE, 0, 0);

    //return oC;
}

void InitZed(OAMObject* oA, int oC, Vec2 pos){
    pos.x += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_ZED, 0, 0);
    pos.y += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_ZED, 0, 0);
    pos.x -= 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_ZED, 0, 0);
    pos.y += 8;
    oC = InitObject(oA, oC, pos, 0, 0, 0, SPR_ZED, 0, 0);

    //return oC;
}
*/