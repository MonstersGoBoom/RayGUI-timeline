
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"
#include "raymath.h"

#define DEF_BORDER_WIDTH 1
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#define _TIMELINE_IMPL_
#include "timeline.h"

float keys[32];

track_t tracks[]=
{
	{"Track0",4,&keys[0]},
	{"Track1",6,&keys[4]},
	{"Track2",6,&keys[10]},
	{"Track3",6,&keys[16]},
	{"Track4",2,&keys[24]},
	{"Track5",2,&keys[26]},
	{"Track6",2,&keys[28]},
	{"Track7",2,&keys[30]},
};

timeline_t testtimeline = 
{
	.frame=0,
	.minValue=0.0f,
	.maxValue=255.0f,
	.nTracks=8,
	.cellHeight=12,
	.tracks=&tracks[0],
	.bounds = (Rectangle){0,64,800,64}
};


timeline_t testtimeline2 = 
{
	.frame=0,
	.minValue=0.0f,
	.maxValue=255.0f,
	.nTracks=8,
	.cellHeight=16,
	.tracks=&tracks[0],
	.bounds = (Rectangle){0,250,1000,128}
};

int main()
{

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(320, 240, "raygui - portable window");

	for (int q=0;q<32;q++)
	{
		keys[q]=(rand()&255);
	}
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground((Color){32,32,32,32});
		//	draw top timeline
		Timeline(&testtimeline);
		//	draw bottom 
		testtimeline2.bounds.width=GetScreenWidth();
		Timeline(&testtimeline2);
		EndDrawing();
	}
	CloseWindow();        // Close window and OpenGL context
	return 0;
}
