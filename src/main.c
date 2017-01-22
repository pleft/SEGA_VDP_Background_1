#include <genesis.h>
#include "resources.h"

int main() {
	
	u16 palette[16];

    // initialization
    VDP_setScreenWidth320();

    // reset all four 16-color palettes to black, starting from PAL0
    VDP_setPaletteColors(PAL0, (u16 *)palette_black, 64);

    // load background
    VDP_drawImageEx(PLAN_A, &background, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX), 0, 0, FALSE, TRUE);

    // copy the image colors to our palette
    memcpy(&palette[0], background.palette->data, 16 * 2);

    // set our palette colors to VDP
    VDP_setPaletteColors(PAL0, (u16 *)palette, 16);

    // fade in (for all 16 colors in our palette fade from black to each color)
    VDP_fadeIn(0, 16 - 1, palette, 50, FALSE);

	while (TRUE) {
        VDP_waitVSync();
    }

    return 0;
}
