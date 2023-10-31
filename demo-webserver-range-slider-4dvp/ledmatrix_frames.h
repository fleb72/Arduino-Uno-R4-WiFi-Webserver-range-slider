#ifndef LEDMATRIX_FRAMES_H
#define LEDMATRIX_FRAMES_H

#include <Arduino_LED_Matrix.h>
const uint32_t frame_slider[12][3] = {
	{
		0xfff800c0,
		0xc00c00c,
		0x800fff
	},
	{
		0xfff400e0,
		0xe00e00e,
		0x400fff
	},
	{
		0xfff20070,
		0x7007007,
		0x200fff
	},
	{
		0xfff10038,
		0x3803803,
		0x80100fff
	},
	{
		0xfff0801c,
		0x1c01c01,
		0xc0080fff
	},
	{
		0xfff0400e,
		0xe00e00,
		0xe0040fff
	},
	{
		0xfff02007,
		0x700700,
		0x70020fff
	},
	{
		0xfff01003,
		0x80380380,
		0x38010fff,
	},
	{
		0xfff00801,
		0xc01c01c0,
		0x1c008fff
	},
	{
		0xfff00400,
		0xe00e00e0,
		0xe004fff
	},
	{
		0xfff00200,
		0x70070070,
		0x7002fff
	},
	{
		0xfff00100,
		0x30030030,
		0x3001fff
	}
};

void print_rangeSlider(int value);

#endif