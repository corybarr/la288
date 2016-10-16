#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//ofSeedRandom(58);
	speed = 0.5f;

	//ofStyle()

	//initialDirection = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
	//initialDirection.normalize();

	//init stuff
	for (int i = 0; i < numTargets; i++) {
		targets.push_back(Target());
		w.push_back(0.f);
	}

	//calculating bird trajectory

	//version 1: simple bird
	//ofVec2f vecToTarget = target1Position - birdPosition;
	//vecToTarget.normalize();
	//float alpha = 0;
	//birdDirection = (1.0 - alpha) * vecToTarget  + alpha * initialDirection;
	//birdDirection.normalize();
	//birdDirection *= speed;


}

//--------------------------------------------------------------
void ofApp::update(){
	//calculate the w vector
	for (int i = 0; i < targets.size(); i++) {
		w[i] = 1.0f / targets[i].position.distanceSquared(birdPosition);
	}

	ofVec3f normedTargetSum = ofVec3f(0, 0, 0);
	for (int i = 0; i < targets.size(); i++) {
		normedTargetSum += w[i] * (targets[i].position - birdPosition).getNormalized();
	}
	birdDirection = normedTargetSum.getNormalized() * speed;

	birdPosition += birdDirection;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	ofBackground(0);
	ofSetColor(ofColor::white);
	ofDrawEllipse(birdPosition, 40, 40);

	for (int i = 0; i < numTargets; i++) {
		targets[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
