#include "ofApp.h"

/*
 
 moved on to Vertical_Horizontal from this version.
 
 key input:
 h = hide/show GUI
 f = toggle fullscreen
 m = hide mouse

 
 important: include ofxGui addons.

 
 changes:
 - random width toggle
 - two widths to change sizes of different coloured rectangles
 - lock width toggle makes uniform width for both sets of rectangles
 - negative speed allows for scrolling in both directions
 
 
 to do:
 - find a smoother method of resetting the x-coordinates once they have reached the edge of the screen
 - find a better method of driving the animation than ofGetElapsedTimeMillis()
 - experiment with using matrices instead of for loops to draw different sized shapes with different colors
 - gradient rectangles
 - scroll vertically and horizontally
 - change background color?
 - try ofxtimeline
 
*/

//--------------------------------------------------------------
void ofApp::setup(){

    gui.setup("panel");
        // initiate GUI
    
    gui.add(width1.setup("width 1", 150, 1, 400));
    gui.add(width2.setup("width 2", 150, 1, 400));
        // width of rectangles. ("name", initial value, min value, max value)
    
    gui.add(speed.setup("speed", 5, -100, 100));
        // speed at which rectangles move. ("name", initial value, min value, max value)
    
    gui.add(color1.set("color 1", ofColor(0,0,10), ofColor(0,0), ofColor(255, 255)));
    gui.add(color2.set("color 2", ofColor(250, 250, 250), ofColor(0,0), ofColor(255, 255)));
        // (starting color, background color for the gui, opacity value (a))
    
    gui.add(sine.setup("sine mode", false));
        // initiate sine mode
    
    gui.add(randomwidths.setup("random width", false));
        // initiate random width mode
    
    gui.add(lockwidths.setup("lock widths", true));
        // start with widths locked at the same value
    
    xloc = - 2 * ofGetWidth();
        // start drawing the rectangles from behind the screen
    
    frame = 0;
        // counter for drawing rectangles successively
    
    hide = false;
    
    swapIn = new ofFbo();
    swapOut = new ofFbo();

}

//--------------------------------------------------------------
void ofApp::update(){

    if (sine == true){
        randomwidths = false;
        lockwidths = false;
        int width = ofMap(sin(ofGetElapsedTimef()), -1, 1, 1, ofGetWidth());
        width1 = width;
        width2 = width;
    }
        // sinusoidal oscillation in the width. change last two values of ofMap to change the range of oscillation.
    
    if (randomwidths == true){
        lockwidths = false;
        sine = false;
        width1 = ofRandom(500);
        width2 = ofRandom(300);
    }
        // randomize both widths
    
    if (lockwidths == true){
        randomwidths = false;
        sine = false;
        float width = width1;
        width2 = width;
    }
        // lock both widths to the same value. must change width 1 in order to change width 2
    
    if (xloc > 0){
        xloc = - 2 * ofGetWidth();
    }
        // reset starting coordinate for drawing rectangles. really glitchy, find a smoother method
    
        // keeps the for loop going - need to find a better method

    xloc = xloc + speed;
        // move rectangles by their x-coordinates
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    ofFill();
        // set rectangles to fill mode
            ofSetColor(color1);
            ofDrawRectangle(xloc+width1*i, 0, width1, ofGetHeight());
            ofSetColor(color2);
            ofDrawRectangle(xloc+width2*i, 0, width2, ofGetHeight());
        // draw every other rectangle a different color
        // xloc+width*i gives a starting x-coordinate that shifts at a given rate.
        // problem: because it starts from just double the screen, it can never be more than that, no matter how many it draws. this is why we shift the xloc periodically.
    
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
