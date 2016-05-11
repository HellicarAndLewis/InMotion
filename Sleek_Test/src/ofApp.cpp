#include "ofApp.h"

#define OUTPUT_WIDTH 1920
#define OUTPUT_HEIGHT 1080

/*

 changes:
 - adjusted width controls
 - smoothed transitions of rectangles from off-screen to on-screen
 - added variable height in rectangles
 - added GUIs for color
 - added lock height parameter
 - added buffer to draw in secondary screen and add a preview screen with controls
 - changed "length" to "height" and "thickness" to "width"
 
 key input:
 h = show/hide GUI
 f = toggle fullscreen
 m = show/hide mouse
 
 important: include ofxGui addons.
 
 assuming we will be working with 3 colors max.
 
 */

//--------------------------------------------------------------
void ofApp::setup(){
    
    buffer.allocate(OUTPUT_WIDTH, OUTPUT_HEIGHT);
    // create a buffer that fits to the size of the output screen (specify these dimensions above)
    
    ofSetBackgroundColor(200);
    // set background color for GUI panel screen
    
    gui.setup("controls");
    // initiate GUI
    
    gui.add(nLinesGroup1.set("# lines group 1", 3, 0, 20));
    gui.add(nLinesGroup2.set("# lines group 2", 4, 0, 20));
    gui.add(nLinesGroup3.set("# lines group 3", 5, 0, 20));
    // sliders to specify the number of lines in each color group
    
    gui.add(color1.set("color 1", ofColor(242, 114, 3), ofColor(0,0), ofColor(255, 255)));
    gui.add(color2.set("color 2", ofColor(14, 222, 229), ofColor(0,0), ofColor(255, 255)));
    gui.add(color3.set("color 3", ofColor(255, 255, 255), ofColor(0,0), ofColor(255, 255)));
    // set colors for each color group. could add sliders for changing on the fly.
    
    gui.add(speed1.set("speed 1", 4, -20, 20));
    gui.add(speed2.set("speed 2", -2, -20, 20));
    gui.add(speed3.set("speed 3", 7, -20, 20));
    // sliders for speed at which rectangles move. ("name", initial value, min value, max value)
    
    gui.add(width1.set("width 1", 2, 0.5, buffer.getWidth()));
    gui.add(width2.set("width 2", 2, 0.5, buffer.getWidth()));
    gui.add(width3.set("width 3", 2, 0.5, buffer.getWidth()));
    // sliders to specify the maximum width of the lines
    
    gui.add(height1.set("height 1", buffer.getHeight(), 0.5, buffer.getHeight()));
    gui.add(height2.set("height 2", buffer.getHeight(), 0.5, buffer.getHeight()));
    gui.add(height3.set("height 3", buffer.getHeight(), 0.5, buffer.getHeight()));
    // sliders to specify the maximum height of the lines
    
    gui.add(vertical.set("vertical mode", false));
    // switch to vertical scrolling

    gui.add(lockheight.set("lock heights", false));
    // lock heights of lines to the heights of the first group

    gui.add(lockwidth.set("lock width", false));
    // lock width of lines to the width of the first group
    
    gui.add(sinewidth.set("sine width", false));
    // initiate sine width mode
    
    gui.add(sineheight.set("sine height", false));
    // initiate sine height mode
    
    gui.add(lockspeeds.set("lock speeds", false));
    // lock speeds to the speed of the first group
    
    gui.add(sinespeed.set("sine speed", false));
    // initiate sine speed mode

    offset1 = 0.3;
    offset2 = -0.5;
    offset3 = 0.8;
    // offset from the sine function for each color group. creates sort of parallax movement. these should be between -1 and 1.
    
    for (int i = 0; i < nLinesGroup1; i++){
        x1.push_back(ofRandom(buffer.getWidth()));
    }
    for (int i = 0; i < nLinesGroup2; i++){
        x2.push_back(ofRandom(buffer.getWidth()));
    }
    for (int i = 0; i < nLinesGroup3; i++){
        x3.push_back(ofRandom(buffer.getWidth()));
    }
    // fill starting x-coordinates values with random values depending on how many lines are in each group.
    
    hide = false;
    // start with the GUI visible
    
    cursor = true;
    // start with cursor visible
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < nLinesGroup1; i++){
        x1.push_back(ofRandom(buffer.getWidth()));
//        if (nLinesGroup1 < )
//            x1.pop_back();
    }
    for (int i = 0; i < nLinesGroup2; i++){
        x2.push_back(ofRandom(buffer.getWidth()));
    }
    for (int i = 0; i < nLinesGroup3; i++){
        x3.push_back(ofRandom(buffer.getWidth()));
    }
    
    
    if (lockwidth){
        float lockedwidth = width1;
        width2 = lockedwidth;
        width3 = lockedwidth;
    }
    // lock width to the width of the first group.
    
    if (lockheight){
        float lockedheight = height1;
        height2 = lockedheight;
        height3 = lockedheight;
    }
    // lock height to the height of the first group.
    
    if (sinewidth){
        lockwidth = false;
        float newwidth = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0.5, buffer.getWidth());
        width1 = newwidth * (offset1 + 1);
        width2 = newwidth * (offset2 + 1);
        width3 = newwidth * (offset3 + 1);
    }
    // sinusoidal oscillation in the width. change last two values of ofMap to change the range of oscillation.
    // lockwidth must be false because the offset values are all different. change these in the setup function to make the lines keep the same widthness as they oscillate.

    
    if (sineheight){
        lockheight = false;
        float newheight = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0.5, buffer.getHeight());
        height1 = newheight * (offset1 + 1);
        height2 = newheight * (offset2 + 1);
        height3 = newheight * (offset3 + 1);
    }
    // sinusoidal oscillation in the height. change last two values of ofMap to change the range of oscillation.
    
    if (lockspeeds){
        sinespeed = false;
        float lockedspeed = speed1;
        speed2 = lockedspeed;
        speed3 = lockedspeed;
    }
    // lock speeds to the speed of the first group.
    // sinespeed must be false because it gives each group a different speed.

    if (sinespeed){
        lockspeeds = false;
        float newspeed = ofMap(sin(ofGetElapsedTimef()), -1, 1, -5, 10);
        speed1 = newspeed + offset1;
        speed2 = newspeed + offset2;
        speed3 = newspeed + offset3;
    }
    // sinusoidal oscillation in the speed. change last two values of ofMap to change the range of oscillation.
    // lockspeeds must be false because the offset values are all different. change these in the setup function to make the lines move at the same speed.
    
//    if (buffer.getWidth() > buffer.getHeight())
//        screensize = buffer.getWidth();
//    else
//        screensize = buffer.getHeight();
//    // determining whether height or width are larger in the screen size in order to determine which value to use in the looping function below.

    for (int i = 0; i < nLinesGroup1; i++){
        x1[i] += speed1;
        if (speed1 > 0 && x1[i] > buffer.getWidth()){
            x1[i] = 0 - width1;
        }
        if (speed1 < 0 && (x1[i] + width1) < 0){
            x1[i] = buffer.getWidth() + width1;
        }
    }
    for (int i = 0; i < nLinesGroup2; i++){
        x2[i] += speed2;
        if (speed2 > 0 && x2[i] > buffer.getWidth()){
            x2[i] = 0 - width2;
        }
        if (speed2 < 0 && (x2[i] + width2) < 0){
            x2[i] = buffer.getWidth() + width2;
        }
    }
    for (int i = 0; i < nLinesGroup3; i++){
        x3[i] += speed3;
        if (speed3 > 0 && x3[i] > buffer.getWidth()){
            x3[i] = 0 - width3;
        }
        if (speed3 < 0 && (x3[i] + width3) < 0){
            x3[i] = buffer.getWidth() + width3;
        }
    }
    // movement functions that ensure the lines will loop smoothly

    if (!cursor)
        ofHideCursor();
    else
        ofShowCursor();
    // show cursor
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    buffer.begin();
    ofClear(0);
    ofFill();
    ofSetColor(0);
    ofDrawRectangle(0, 0, buffer.getWidth(), buffer.getHeight());
    for (int i = 0; i < nLinesGroup1; i++){
        ofSetColor(color1);
        if (vertical == true)
            ofDrawRectangle((buffer.getWidth()-width1)/2, x1[i], width1, height1);
        else
            ofDrawRectangle(x1[i], (buffer.getHeight()-height1)/2, width1, height1);
    }
    for (int i = 0; i < nLinesGroup2; i++){
        ofSetColor(color2);
        if (vertical == true)
            ofDrawRectangle((buffer.getWidth()-width2)/2, x2[i], width2, height2);
        else
            ofDrawRectangle(x2[i], (buffer.getHeight()-height2)/2, width2, height2);
    }
    for (int i = 0; i < nLinesGroup3; i++){
        ofSetColor(color3);
        if (vertical == true)
            ofDrawRectangle((buffer.getWidth()-width3)/2, x3[i], width3, height3);
        else
            ofDrawRectangle(x3[i], (buffer.getHeight()-height3)/2, width3, height3);
    }
    // draw lines. if vertical mode is on, switch x coordinates to y-positions
    
    buffer.end();
    if (!hide){
        gui.draw();
    }
    
    buffer.draw(ofGetScreenWidth(), 0);
    buffer.draw(ofGetScreenWidth()/4, ofGetScreenHeight()/4, ofGetScreenWidth()/2, ofGetScreenHeight()/2);
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
