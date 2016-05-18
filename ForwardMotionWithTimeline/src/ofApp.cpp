#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    speedxMax = 20;
    speedxMin = -20;
    speedyMax = 10;
    speedyMin = - 10;
    
    timeline.setup();
    timeline.setDurationInSeconds(30);
    timeline.setLoopType(OF_LOOP_NORMAL);
    timeline.addCurves("speed x", ofRange(speedxMin, speedxMax));
    timeline.addCurves("speed y", ofRange(speedyMin, speedyMax));
    
    numberOfLines = 10;
    startingX = ofGetWidth()/2;
    startingY = ofGetHeight()/2;
    lineW = 5;
    endingX = ofGetWidth()/(numberOfLines - 1);
    endingY = 0;
    
    for (int i = 0; i < numberOfLines; i++){
        moveLine tempLine;
        tempLine.setup(numberOfLines, startingX, startingY, lineW, i*endingX, endingY);
        myLines.push_back(tempLine);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < myLines.size(); i++){
        myLines[i].update(timeline.getValue("speed x"), timeline.getValue("speed y"));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < myLines.size(); i++){
        myLines[i].draw();
    }
    
    timeline.draw();
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
