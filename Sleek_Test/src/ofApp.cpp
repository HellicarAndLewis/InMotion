#include "ofApp.h"

/*

 changes:
 - added function to lock thicknesses of color groups
 - removed noise function that varied thickness
 - removed "w#" variables, as they were redundant from "thickness#" variables
 - consolidated draw functions
 
 key input:
 h = hide/show GUI
 f = toggle fullscreen
 m = hide mouse
 
 important: include ofxGui addons.
 
 assuming we will be working with 3 colors max.
 
 */

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofSetBackgroundColor(0);
    // set background color to black
    
    gui.setup("controls");
    // initiate GUI
    
    color1.set("color 1", ofColor(242, 114, 3), ofColor(0,0), ofColor(255, 255));
    color2.set("color 2", ofColor(14, 222, 229), ofColor(0,0), ofColor(255, 255));
    color3.set("color 3", ofColor(255, 255, 255), ofColor(0,0), ofColor(255, 255));
    // set colors for each color group. could add sliders for changing on the fly.
    
    gui.add(speed1.setup("speed1", 1, -20, 20));
    gui.add(speed2.setup("speed2", 0.7, -20, 20));
    gui.add(speed3.setup("speed3", 0.1, -20, 20));
    // sliders for speed at which rectangles move. ("name", initial value, min value, max value)
    
    nLinesGroup1 = 2;
    nLinesGroup2 = 2;
    nLinesGroup3 = 3;
    // initiate the number of lines from each color group will appear on the screen at one time.
    
    gui.add(thickness1.setup("thickness1", 1, 0.5, 5));
    gui.add(thickness2.setup("thickness2", 3, 0.5, 5));
    gui.add(thickness3.setup("thickness3", 2, 0.5, 5));
    // sliders to specify the maximum thickness of the lines

    gui.add(lockspeeds.setup("lock speeds", false));
    // lock speeds to the speed of the first group

    gui.add(lockthickness.setup("lock thickness", false));
    // lock thickness of lines to the thickness of the first group
    
    gui.add(sinespeed.setup("sine speed", false));
    // initiate sine speed mode
    
    gui.add(vertical.setup("vertical mode", false));
    // switch to vertical scrolling
    
    offset1 = 0.3;
    offset2 = 1;
    offset3 = -0.6;
    // offset from the sine function for each color group. creates sort of parallax movement. these should be between -1 and 1.
    
    
    for (int i = 0; i < nLinesGroup1; i++){
        x1.push_back(ofRandom(ofGetWidth()));
    }
    for (int i = 0; i < nLinesGroup2; i++){
        x2.push_back(ofRandom(ofGetWidth()));
    }
    for (int i = 0; i < nLinesGroup3; i++){
        x3.push_back(ofRandom(ofGetWidth()));
    }
    // fill starting x-coordinates values with random values depending on how many lines are in each group.
    
    hide = false;
    // start with the GUI visible

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (sinespeed == true){
        lockspeeds = false;
        float newspeed = ofMap(sin(ofGetElapsedTimef()), -1, 1, -5, 10);
        speed1 = newspeed + offset1;
        speed2 = newspeed + offset2;
        speed3 = newspeed + offset3;
    }
    // sinusoidal oscillation in the speed. change last two values of ofMap to change the range of oscillation.
    // lockspeeds must be false because the offset values are all different. change these in the setup function to make the lines move at the same speed.
    
    if (lockspeeds == true){
        sinespeed = false;
        float lockedspeed = speed1;
        speed2 = lockedspeed;
        speed3 = lockedspeed;
    }
    // lock speeds to the speed of the first group.
    // sinespeed must be false because it gives each group a different speed.
    
    if (lockthickness == true){
        float lockedthickness = thickness1;
        thickness2 = lockedthickness;
        thickness3 = lockedthickness;
    }
    // lock thickness to the thickness of the first group.
    
    for (int i = 0; i < nLinesGroup1; i++){
        x1[i] += speed1;
        if (speed1 > 0 && x1[i] > ofGetWidth()){
            x1[i] = 0;
        }
        if (speed1 < 0 && x1[i] < 0){
            x1[i] = ofGetWidth();
        }
    }
    for (int i = 0; i < nLinesGroup2; i++){
        x2[i] += speed2;
        if (speed2 > 0 && x2[i] > ofGetWidth()){
            x2[i] = 0;
        }
        if (speed2 < 0 && x2[i] < 0){
            x2[i] = ofGetWidth();
        }
    }
    for (int i = 0; i < nLinesGroup3; i++){
        x3[i] += speed3;
        if (speed3 > 0 && x3[i] > ofGetWidth()){
            x3[i] = 0;
        }
        if (speed3 < 0 && x3[i] < 0){
            x3[i] = ofGetWidth();
        }
    }
    // movement functions that ensure the lines will loop
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofFill();

    for (int i = 0; i < nLinesGroup1; i++){
        ofSetColor(color1);
        if (vertical == true)
            ofDrawRectangle(0, x1[i], ofGetWidth(), thickness1);
        else
            ofDrawRectangle(x1[i], 0, thickness1, ofGetHeight());
    }
    for (int i = 0; i < nLinesGroup2; i++){
        ofSetColor(color2);
        if (vertical == true)
            ofDrawRectangle(0, x2[i], ofGetWidth(), thickness2);
        else
            ofDrawRectangle(x2[i], 0, thickness2, ofGetHeight());
    }
    for (int i = 0; i < nLinesGroup3; i++){
        ofSetColor(color3);
        if (vertical == true)
            ofDrawRectangle(0, x3[i], ofGetWidth(), thickness3);
        else
            ofDrawRectangle(x3[i], 0, thickness3, ofGetHeight());
    }
    // draw lines. if vertical mode is on, switch x coordinates to y-positions
    
    if (!hide){
        gui.draw();
    }
    // gui must be drawn after the animation so that it is visible on top
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 'f')
        ofToggleFullscreen();
    
    if (key == 'm')
        ofHideCursor();
    
    if (key == 'h')
        hide = !hide;
    
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
