#pragma once

#include "ofMain.h"

class Mover 
{
public:
	Mover();
	void checkEdges();
	void update();
	void draw();

private:
	ofVec2f location;
	ofVec2f velocity;
	float topspeed;
};
