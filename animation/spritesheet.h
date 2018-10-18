#pragma once
#include <allegro5/allegro.h>
#include "Rect.h"
#include "xmlparser.h"
#include <string>
using namespace std;
class sprites
{
public:
	sprites(string name);
	
	int getRange(int i);
	string getName(int i);
	rect getBox(int i, int k);
	ALLEGRO_BITMAP *getFromRect(rect loc);

private:
	ALLEGRO_BITMAP * sheet;
	string animations[10];
	int range[10];
	rect imageboxes[10][20];
};

