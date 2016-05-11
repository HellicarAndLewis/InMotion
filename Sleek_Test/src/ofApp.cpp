#include "ofApp.h"

/*

 changes:
 - added sine function for width variation
 - created variable to store largest screen size, to ensure that looping of lines functions despite changes in size
 - added toggle functionality for showing/hiding the mouse
 
 key input:
 h = show/hide GUI
 f = toggle fullscreen
 m = show/hide mouse
 
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
    
    gui.add(speed1.setup("speed1", 4, -20, 20));
    gui.add(speed2.setup("speed2", -2, -20, 20));
    gui.add(speed3.setup("speed3", 7, -20, 20));
    // sliders for speed at which rectangles move. ("name", initial value, min value, max value)
    
    nLinesGroup1 = 2;
    nLinesGroup2 = 2;
    nLinesGroup3 = 3;
    // initiate the number of lines from each color group will appear on the screen at one time.
    
    gui.add(thickness1.setup("thickness1", 1, 0.5, 5));
    gui.add(thickness2.setup("thickness2", 3, 0.5, 5));
    gui.add(thickness3.setup("thickness3", 2, 0.5, 5));
    // sliders to specify the maximum thickness of the lines
    
    gui.add(vertical.setup("vertical mode", false));
    // switch to vertical scrolling

    gui.add(lockspeeds.setup("lock speeds", false));
    // lock speeds to the speed of the first group

    gui.add(lockthickness.setup("lock thickness", false));
    // lock thickness of lines to the thickness of the first group
    
    gui.add(sinespeed.setup("sine speed", false));
    // initiate sine speed mode
    
    gui.add(sinethickness.setup("sine thickness", false));
    // initiate sine thickness mode
    
    
    offset1 = 0.3;
    offset2 = -0.5;
    offset3 = 0.8;
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
    
    cursor = true;
    // start with cursor visible

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
    
    if (sinethickness == true){
        lockthickness = false;
        float newthickness = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0.5, 5);
        thickness1 = newthickness * (offset1 + 1);
        thickness2 = newthickness * (offset2 + 1);
        thickness3 = newthickness * (offset3 + 1);
    }
    // sinusoidal oscillation in the thickness. change last two values of ofMap to change the range of oscillation.
    // lockwidth must be false because the offset values are all different. change these in the setup function to make the lines keep the same widthness as they oscillate.
    
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
    
    if (ofGetWidth() > ofGetHeight())
        screensize = ofGetWidth();
    else
        screensize = ofGetHeight();
    // determining whether height or width are larger in the screen size in order to determine which value to use in the looping function below.
    
    for (int i = 0; i < nLinesGroup1; i++){
        x1[i] += speed1;
        if (speed1 > 0 && x1[i] > screensize){
            x1[i] = 0;
        }
        if (speed1 < 0 && x1[i] < 0){
            x1[i] = screensize;
        }
    }
    for (int i = 0; i < nLinesGroup2; i++){
        x2[i] += speed2;
        if (speed2 > 0 && x2[i] > screensize){
            x2[i] = 0;
        }
        if (speed2 < 0 && x2[i] < 0){
            x2[i] = screensize;
        }
    }
    for (int i = 0; i < nLinesGroup3; i++){
        x3[i] += speed3;
        if (speed3 > 0 && x3[i] > screensize){
            x3[i] = 0;
        }
        if (speed3 < 0 && x3[i] < 0){
            x3[i] = screensize;
        }
    }
    // movement functions that ensure the lines will loop
    
    if (cursor == false)
        ofHideCursor();
    else
        ofShowCursor();
    // show cursor
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
    // toggle fullscreen mode on or off
    
    if (key == 'm')
        cursor = !cursor;
    // hide cursor
    
    if (key == 'h')
        hide = !hide;
    // hide GUI panel
    
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
