#include "ofApp.h"

ofPoint P1;
ofPoint P2;
ofPoint pos;
float rX;
float rY;
float rZ;
ofFbo fbo;
ofColor black(0,0,0);

//--------------------------------------------------------------
void ofApp::setup(){
    P1 = ofPoint(-20,0);
    P2 = ofPoint(20,0);
    pos = ofPoint(ofGetWidth(),ofGetHeight(),0);
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    ofSetBackgroundColor(black);

}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.4) * 180.0;
    rY = ofSignedNoise(time * 0.7) * 180.0;
    rZ = ofSignedNoise(time * 0.5) * 180.0;
    
    float x = ofMap(ofSignedNoise(time * 0.5), -1, 1, 0, ofGetWidth());
    float y = ofMap(ofSignedNoise(time * 0.2), -1, 1, 0, ofGetHeight());
    float z = ofMap(ofSignedNoise(time * 0.5), -1, 1, -800, 800);
    
    pos = ofPoint(x, y, z);


}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofPushStyle();
    ofSetColor(0,0,0,1);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPopStyle();
    
    ofPushMatrix();
    ofTranslate(pos);
    
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    ofPushStyle();
    ofSetColor(255,255,30);
    ofDrawLine(P1,P2);
    ofPopStyle();
    ofPopMatrix();
    fbo.end();
    
    fbo.draw(0,0);

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
