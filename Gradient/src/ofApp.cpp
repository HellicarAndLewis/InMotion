#include "ofApp.h"

/*
 
 this version uses ofImage in place of ofDrawRectangle in order to draw pixel by pixel and create a gradient. the result is much slower than ofDrawRectangle.
 
 key input:
 h = hide/show GUI
 f = toggle fullscreen
 m = hide mouse
 s = toggle sine mode
 
 
 important: include ofxGui addons.
 
 
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
    
    gui.add(width1.setup("width 1", ofGetWidth(), 1, 400));
    gui.add(width2.setup("width 2", ofGetWidth(), 1, 400));
    // width of rectangles. ("name", initial value, min value, max value). initial value is set to screen width, which will be the maximum size of the rectangles. for some reason, the size specified here becomes the maximum size.
    
    gui.add(color1.setup("color 1.1", 200, 1, 255));
    gui.add(color2.setup("color 1.2", 100, 1, 255));
    gui.add(color3.setup("color 2.1", 150, 1, 255));
    gui.add(color4.setup("color 2.2", 255, 1, 255));
    // r and b values for rectangles (see drawGradient())
    
    gui.add(speed.setup("speed", 5, -100, 100));
    // speed at which rectangles move. ("name", initial value, min value, max value)
    
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
    
    rect1.allocate(width1, ofGetHeight(), OF_IMAGE_COLOR);
    rect2.allocate(width2, ofGetHeight(), OF_IMAGE_COLOR);
    drawGradient();
    // starts in fullscreen so that the height and width are initiated with their maximum values
    
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
    
    frame = ofGetElapsedTimeMillis();
    // keeps the for loop going - need to find a better method
    
    xloc = xloc + speed;
    // move rectangles by their x-coordinates
    
    drawGradient();
}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i = 0; i < frame; i++){
        if (i % 2 == 0){
            rect1.draw(xloc+width1*i,0);
        }
        else{
            rect2.draw(xloc+width2*i,0);
        }
    }
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
void ofApp::drawGradient(){
    
    for (int x=0; x<width1; x++) {
        for (int y=0; y<ofGetHeight(); y++) {
            rect1.setColor(x, y, ofColor::fromHsb(color1, x, color2));
        }
    }
    rect1.update();

    for (int x=0; x<width2; x++) {
        for (int y=0; y<ofGetHeight(); y++) {
            rect2.setColor(x, y, ofColor::fromHsb(color3, x, color4));
        }
    }
    rect2.update();
    // set gradient colors by varying by x coordinates, then draw rectangles.
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