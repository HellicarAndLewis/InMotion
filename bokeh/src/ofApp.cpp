#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundColor(200);
    // set background color for GUI panel screen
    
    gui.setup("controls");
    // initiate GUI
    
    gui.add(nLinesGroup1.set("circles group 1", 3, 0, 20));
    gui.add(nLinesGroup2.set("circles group 2", 4, 0, 20));
    gui.add(nLinesGroup3.set("circles group 3", 5, 0, 20));
    // sliders to specify the number of lines in each color group
    
    gui.add(bckgrndcolor.set("background color", ofColor(0, 0, 0), ofColor(0,0), ofColor(255, 255)));
    gui.add(color1.set("color 1", ofColor(255, 0, 0, 150), ofColor(0,0), ofColor(255, 255)));
    gui.add(color2.set("color 2", ofColor(150, 150, 150, 200), ofColor(0,0), ofColor(255, 255)));
    gui.add(color3.set("color 3", ofColor(255, 255, 255, 200), ofColor(0,0), ofColor(255, 255)));
    // set colors for each color group. could add sliders for changing on the fly.
    
    gui.add(speed1.set("speed 1", 5, -20, 20));
    gui.add(speed2.set("speed 2", 6, -20, 20));
    gui.add(speed3.set("speed 3", 7, -20, 20));
    // sliders for speed at which rectangles move. ("name", initial value, min value, max value)
    
    gui.add(height1.set("radius 1", 50, 0.5, ofGetHeight()/3));
    gui.add(height2.set("radius 2", 55, 0.5, ofGetHeight()/3));
    gui.add(height3.set("radius 3", 28, 0.5, ofGetHeight()/3));
    // sliders to specify the maximum height of the lines
    
    
    gui.add(lockheight.set("lock radius", false));
    // lock heights of lines to the heights of the first group
    
    gui.add(lockspeeds.set("lock speeds", false));
    // lock speeds to the speed of the first group
    
    gui.add(sinespeed.set("sine speed", false));
    // initiate sine speed mode
    
    offset1 = 0.3;
    offset2 = 0.5;
    offset3 = 0.8;
    // offset from the sine function for each color group. creates sort of parallax movement. these should be between -1 and 1.
    
    for (int i = 0; i < nLinesGroup1.getMax(); i++){
        x1.push_back(ofRandom(ofGetWidth()));
    }
    for (int i = 0; i < nLinesGroup2.getMax(); i++){
        x2.push_back(ofRandom(ofGetWidth()));
    }
    for (int i = 0; i < nLinesGroup3.getMax(); i++){
        x3.push_back(ofRandom(ofGetWidth()));
    }
    // fill starting x-coordinates values with random values depending on how many lines are in each group.
    
    for (int i = 0; i < nLinesGroup1.getMax(); i++){
        y1.push_back(ofRandom(ofGetHeight()/3, 2*(ofGetHeight()/3)));
    }
    for (int i = 0; i < nLinesGroup2.getMax(); i++){
        y2.push_back(ofRandom(ofGetHeight()/3, 2*(ofGetHeight()/3)));
    }
    for (int i = 0; i < nLinesGroup3.getMax(); i++){
        y3.push_back(ofRandom(ofGetHeight()/3, 2*(ofGetHeight()/3)));
    }
    
    hide = false;
    // start with the GUI visible
    
    cursor = true;
    // start with cursor visible
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (lockheight){
        float lockedheight = height1;
        height2 = lockedheight;
        height3 = lockedheight;
    }
    // lock height to the height of the first group.
        
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
    
    for (int i = 0; i < nLinesGroup1; i++){
        x1[i] += speed1;
        if (speed1 > 0 && x1[i] > ofGetWidth()+height1){
            x1[i] = 0 - height1;
        }
        if (speed1 < 0 && (x1[i] + height1) < 0){
            x1[i] = ofGetWidth() + height1;
        }
    }
    for (int i = 0; i < nLinesGroup2; i++){
        x2[i] += speed2;
        if (speed2 > 0 && x2[i] > ofGetWidth()+height2){
            x2[i] = 0 - height2;
        }
        if (speed2 < 0 && (x2[i] + height2) < 0){
            x2[i] = ofGetWidth() + height2;
        }
    }
    for (int i = 0; i < nLinesGroup3; i++){
        x3[i] += speed3;
        if (speed3 > 0 && x3[i] > ofGetWidth()+height3){
            x3[i] = 0 - height3;
        }
        if (speed3 < 0 && (x3[i] + height3) < 0){
            x3[i] = ofGetWidth() + height3;
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
    
    ofClear(0);
    
    ofFill();
    
    ofSetColor(bckgrndcolor);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetCircleResolution(150);
    for (int i = 0; i < nLinesGroup1; i++){
        ofSetColor(color1);
            ofDrawCircle(x1[i], y1[i], height1);
    }
    for (int i = 0; i < nLinesGroup2; i++){
        ofSetColor(color2);
            ofDrawCircle(x2[i], y2[i], height2);
    }
    for (int i = 0; i < nLinesGroup3; i++){
        ofSetColor(color3);
            ofDrawCircle(x3[i], y3[i], height3);
    }
    // draw circles
    
    if (!hide)
        gui.draw();
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
    
    if(key == 's'){
        gui.saveToFile("settings.xml");
    }
    
    if(key == 'l'){
        cout << "load" << endl;
        gui.loadFromFile("settings.xml");
    }

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
