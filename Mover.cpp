#include "Mover.h"



Mover::Mover()
{
	location.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	velocity.set(0, 0);
	topspeed = 5;
}

void Mover::checkEdges()
{
	if (location.x > ofGetWidth()) {
		location.x = 0;
	}
	else if (location.x < 0) {
		location.x = ofGetWidth();
	}

	if (location.y > ofGetHeight()) {
		location.y = 0;
	}
	else if (location.y < 0) {
		location.y = ofGetHeight();
	}
}


void Mover::update() {
	// Compute a vector that points from location to mouse
	ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
	ofVec2f acceleration(mouse);
	acceleration -= location;
	// Set magnitude of acceleration
	acceleration.normalize();
	acceleration *= 0.2;

	// Velocity changes according to acceleration
	velocity += acceleration;
	// Limit the velocity by topspeed
	velocity.limit(topspeed);
	// Location changes by velocity
	location += velocity;
}


void Mover::draw() {
	ofFill();
	ofSetColor(127, 200);
	ofEnableAlphaBlending();
	ofEllipse(location.x, location.y, 48, 48);
	ofDisableAlphaBlending();

	ofNoFill();
	ofSetColor(0);
	ofSetLineWidth(2);
	ofEllipse(location.x, location.y, 48, 48);
}

