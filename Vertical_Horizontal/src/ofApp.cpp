#include "ofApp.h"

/*
 
 key input:
 h = hide/show GUI
 f = toggle fullscreen
 m = hide mouse
 
 
 important: include ofxGui addons.
 
 
 changes:
 - added vertical scrolling
 - added sine movement in the speed, distinguish between this and width
 - added perlin noise function for smoother variations in width change
 
 to do:
 - find a smoother method of resetting the x-coordinates once they have reached the edge of the screen
 - find a better method of driving the animation than ofGetElapsedTimeMillis()
 - experiment with using matrices instead of for loops to draw different sized shapes with different colors
 - gradient rectangles
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
    
    gui.add(vertical.setup("vertical mode", false));
    // switch to vertical scrolling
    
    gui.add(sinespeed.setup("sine speed", false));
    // initiate sine speed mode
    
    gui.add(sinewidth.setup("sine width", false));
    // initiate sine width mode
    
    gui.add(randomwidths.setup("random width", false));
    // initiate random width mode
    
    gui.add(lockwidths.setup("lock widths", true));
    // start with widths locked at the same value

    gui.add(noisewidths.setup("noise widths", false));
    // initiate noise width mode
    
    xloc = - 2 * ofGetWidth();
    yloc = - 2 * ofGetHeight();
    // start drawing the rectangles from behind (or above) the screen
    
    frame = 0;
    // counter for drawing rectangles successively
    
    hide = false;
    // start with the GUI visible
    
    for(int i = 0 ; i < 2; i++)
        noiseseeds.push_back(ofRandom(0,10000));
    // start at two random points on the perlin noise graph. to use in "noise width" mode later on.
    
    stepsize = 20;
    // step size with which to travel through the noise graph
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (sinespeed == true){
        sinewidth = false;
        float newspeed = ofMap(sin(ofGetElapsedTimef()), -1, 1, -5, 5);
        speed = newspeed;
    }
    // sinusoidal oscillation in the speed. change last two values of ofMap to change the range of oscillation.
    
    if (sinewidth == true){
        randomwidths = false;
        lockwidths = false;
        sinespeed = false;
        int width = ofMap(sin(ofGetElapsedTimef()), -1, 1, 1, ofGetWidth());
        width1 = width;
        width2 = width;
    }
    // sinusoidal oscillation in the width. change last two values of ofMap to change the range of oscillation.
    
    if (randomwidths == true){
        lockwidths = false;
        sinewidth = false;
        width1 = ofRandom(500);
        width2 = ofRandom(300);
    }
    // randomize both widths
    
    if (noisewidths == true){
        lockwidths = false;
        sinewidth = false;
        sinespeed = true;
        width1 = ofMap(ofNoise(noiseseeds[1]), 0, 1, 1, 50);
        width2 = ofMap(ofNoise(noiseseeds[2]), 0, 1, 1, 50);
        noiseseeds[1] += 0.01;
        noiseseeds[2] += 0.01;
    }
    // use perlin noise to make a smooth randomness in the width. change the last two values in ofmap to change the range of width.
    
    
    if (lockwidths == true){
        randomwidths = false;
        sinewidth = false;
        float width = width1;
        width2 = width;
    }
    // lock both widths to the same value. must change width 1 in order to change width 2
    
    if (xloc > 0){
        xloc = - 2 * ofGetWidth();
    }
    if (yloc > 0){
        yloc = - 2 * ofGetHeight();
    }
    // reset starting coordinate for drawing rectangles. really glitchy, find a smoother method
    
    frame = ofGetElapsedTimeMillis();
    // keeps the for loop going - need to find a better method
    
    xloc = xloc + speed;
    // move rectangles by their x-coordinates
    
    yloc = yloc + speed;
    // move rectangles by their y-coordinates
    
    if (!cursor)
        ofShowCursor();
    else
        ofHideCursor();
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    ofFill();
    // set rectangles to fill mode
    
    if (vertical == true){
        for (int i = 0; i < frame; i++){
            if (i % 2 == 0){
                ofSetColor(color1);
                ofDrawRectangle(0, yloc+width1*i, ofGetWidth(), width1);
            }
            else{
                ofSetColor(color2);
                ofDrawRectangle(0, yloc+width1*i, ofGetWidth(), width1);
            }
        }
    }
    // vertical scrolling
    else{
        for (int i = 0; i < frame; i++){
            if (i % 2 == 0){
                ofSetColor(color1);
                ofDrawRectangle(xloc+width1*i, 0, width1, ofGetHeight());
            }
            else{
                ofSetColor(color2);
                ofDrawRectangle(xloc+width2*i, 0, width2, ofGetHeight());
            }
        }
    }
    // horizontal scrolling

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
        cursor = !cursor;
    
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