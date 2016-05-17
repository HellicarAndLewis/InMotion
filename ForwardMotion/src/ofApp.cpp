#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    speedxMax = 20;
    speedxMin = -20;
    speedyMax = 10;
    speedyMin = - 10;
    
    gui.setup();
    gui.add(speedx.set("speed x", 0, speedxMin, speedxMax));
    gui.add(speedy.set("speed y", 0, speedyMin, speedyMax));
    gui.add(sineX.set("sine x", false));
    gui.add(sineY.set("sine y", false));
    
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
    
    if (sineX)
        speedx = ofMap(sin(ofGetElapsedTimef()), -1, 1, speedxMin, speedxMax);
    
    if (sineY)
        speedy = ofMap(sin(ofGetElapsedTimef()), -1, 1, speedyMin, speedyMax);
    // these are weird and don't cross the screen evenly
    
    for (int i = 0; i < myLines.size(); i++){
        myLines[i].update(speedx, speedy);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    gui.draw();
    
    for (int i = 0; i < myLines.size(); i++){
        myLines[i].draw();
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
