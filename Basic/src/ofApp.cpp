#include "ofApp.h"

/*
 
 key input:
 H = hide/show GUI
 F = toggle fullscreen
 M = hide mouse

 
 important: include ofxGui addons.

 
 to do:
 - find a smoother method of resetting the x-coordinates once they have reached the edge of the screen
 - find a better method of driving the animation than ofGetElapsedTimeMillis()
 - experiment with using matrices instead of for loops to draw different sized shapes with different colors
 
*/

//--------------------------------------------------------------
void ofApp::setup(){

    gui.setup("panel");
        // initiate GUI
    
    gui.add(width.setup("WIDTH", 150, 1, 400));
        // width of rectangles. ("name", initial value, height of slider, max value)
    
    gui.add(speed.setup("SPEED", 5, 0.5, 100));
        // speed at which rectangles move from left to right. ("name", initial value, height of slider, max value)
    
    gui.add(color1.set("COLOR 1", ofColor(0,0,10), ofColor(0,0), ofColor(255, 255)));
    gui.add(color2.set("COLOR 2", ofColor(250, 250, 250), ofColor(0,0), ofColor(255, 255)));
        // (starting color, background color for the gui, opacity value (a))
    
    xloc = - 2 * ofGetWidth();
        // start drawing the rectangles from behind the screen
    
    frame = 0;
        // counter for drawing rectangles successively
    
    sine = false;
    
    hide = false;

}

//--------------------------------------------------------------
void ofApp::update(){

    if (sine == true){
        width = ofMap(sin(ofGetElapsedTimef()), -1, 1, 1, ofGetWidth());
    }
    else{
        width = 150;
    }
        // sinusoidal oscillation in the width
    
    if (xloc > 0){
        xloc = - 2 * ofGetWidth();
    }
        // reset starting coordinate for drawing rectangles. really glitchy, find a smoother method
    
    frame = ofGetElapsedTimeMillis();
        // keeps the for loop going - need to find a better method

    xloc = xloc + speed;
        // move rectangles by their x-coordinates

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofFill();
        // set rectangles to fill mode

    for (int i = 0; i < frame; i++){
        if (i % 2 == 0){
            ofSetColor(color1);
            ofDrawRectangle(xloc+width*i, 0, width, ofGetHeight());
        }
        else{
            ofSetColor(color2);
            ofDrawRectangle(xloc+width*i, 0, width, ofGetHeight());
        }
    }
        // draw every other rectangle a different color
        // xloc+width*i gives a starting x-coordinate that shifts at a given rate.
        // problem: because it starts from just double the screen, it can never be more than that, no matter how many it draws
    
    if (!hide){
        gui.draw();
    }
        // gui must be drawn after the animation so that it is visible
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 'f')
        ofToggleFullscreen();
    
    if (key == 'm')
        ofHideCursor();
    
    if (key == 'h')
        hide = !hide;

    if (key == 's')
        sine = !sine;
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
