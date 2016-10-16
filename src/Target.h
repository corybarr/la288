#pragma once
#include "ofMain.h"

class Target {
public:
	ofVec3f position;
	ofColor col;

	Target() {
		//ofSeedRandom(6);
		float halfWidth = ofGetWidth() * .5f;
		float halfHeight = ofGetHeight() * .5f;
		position = ofVec2f(ofRandom(-halfWidth, halfWidth),
			ofRandom(-halfHeight, halfHeight));

		col = ofColor(ofRandom(125, 255), ofRandom(125, 255), ofRandom(125, 255));
	}

	void draw() {
		ofPushStyle();
		ofSetColor(col);
		ofDrawRectangle(position.x, position.y, 30, 30);
		ofPopStyle();
	}
};