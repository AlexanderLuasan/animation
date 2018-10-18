#include "spritesheet.h"
#include <vector>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;
sprites::sprites(string name)
{
	sheet = al_load_bitmap("pop.png");
	xmlfile boxfile;
	boxfile.setfile(name.c_str());
			vector<string> boxes = boxfile.nav().get("walk").getkeys();
			animations[0] = "walk";
			
			for (int ii = 0; ii < boxes.size(); ii++) {
				int x = stoi(boxfile.nav().get("walk").get(boxes[ii]).head("x"));
				int y = stoi(boxfile.nav().get("walk").get(boxes[ii]).head("y"));
				int w = stoi(boxfile.nav().get("walk").get(boxes[ii]).head("width"));
				int h = stoi(boxfile.nav().get("walk").get(boxes[ii]).head("height"));
				imageboxes[0][ii] = rect(x,y,w,h);
			}
			range[0] = boxes.size();

}

int sprites::getRange(int i)
{
	return range[i];
}

string sprites::getName(int i)
{
	return animations[i];
}

rect sprites::getBox(int i, int k)
{
	return imageboxes[i][k];
}

ALLEGRO_BITMAP * sprites::getFromRect(rect loc)
{
	return al_create_sub_bitmap(sheet, loc.getx(),loc.gety(),loc.getw(),loc.geth());
}
