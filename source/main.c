#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <tonc.h>

#include "SelfDefs.h"
#include "Logic.h"

OBJ_ATTR oamArray[OAM_MAX];		// OAM Buffer
OAMObject objArray[OAM_MAX];

int main(){
	// Init
	oam_init(oamArray, OAM_MAX);
	int oamCount = 0;
	
	REG_DISPCNT = DCNT_OBJ | DCNT_BG0 | DCNT_BG1;
	while(1){
		vid_vsync();
		
		UpdateObjects(oamArray, objArray, oamCount);

		oam_copy(oam_mem, oamArray, oamCount);
	}
}