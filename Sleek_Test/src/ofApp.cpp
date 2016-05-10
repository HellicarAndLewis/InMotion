#include "ofApp.h"

/*

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
    
    gui.setup("controls");
    // initiate GUI
    
    color1.set("color 1", ofColor(242, 114, 3), ofColor(0,0), ofColor(255, 255));
    color2.set("color 2", ofColor(14, 222, 229), ofColor(0,0), ofColor(255, 255));
    color3.set("color 3", ofColor(255, 255, 255), ofColor(0,0), ofColor(255, 255));
    
    gui.add(speed1.setup("speed1", 1, -20, 20));
    gui.add(speed2.setup("speed2", 0.7, -20, 20));
    gui.add(speed3.setup("speed3", 0.1, -20, 20));
    // sliders for speed at which rectangles move. ("name", initial value, min value, max value)
    
    nLinesGroup1 = 2;
    nLinesGroup2 = 2;
    nLinesGroup3 = 2;
    // initiate the number of lines from each color group will appear on the screen at one time.
    
    gui.add(thickness1.setup("thickness1", 1, 0.5, 5));
    gui.add(thickness2.setup("thickness2", 3, 0.5, 5));
    gui.add(thickness3.setup("thickness3", 2, 0.5, 5));
    // sliders to specify the maximum thickness of the lines

    gui.add(lockspeeds.setup("lock speeds", false));
    // lock speeds to the speed of the first group
    
    gui.add(noise.setup("noise", false));
    // initiate noise width mode
    
    gui.add(sinespeed.setup("sine speed", false));
    // initiate sine speed mode
    
    gui.add(vertical.setup("vertical mode", false));
    // switch to vertical scrolling
    
    noiseseed1 = ofRandom(1000);
    noiseseed2 = ofRandom(1000);
    noiseseed3 = ofRandom(1000);
    
    offset1 = 0.3;
    offset2 = 1;
    offset3 = -0.6;
    // these should be between -1 and 1
    
    for (int i = 0; i < nLinesGroup1; i++){
        x1.push_back(ofRandom(ofGetWidth()));
        w1.push_back(ofRandom(0, 10));
    }
    
    for (int i = 0; i < nLinesGroup2; i++){
        x2.push_back(ofRandom(ofGetWidth()));
        w2.push_back(ofRandom(0, 10));
    }
    
    for (int i = 0; i < nLinesGroup3; i++){
        x3.push_back(ofRandom(ofGetWidth()));
        w3.push_back(ofRandom(0, 10));
    }
    
    hide = false;
    // start with the GUI visible
    
}

//--------------------------------------------------------------
void ofApp::update(){

 /*
  
  work on allowing for negative speed
  
  if (speed1 < 0 && x1[i] < 0)
 
  */
    if (lockspeeds == true){
        sinespeed = false;
        float lockedspeed = speed1;
        speed2 = lockedspeed;
        speed3 = lockedspeed;
    }
    
    if (sinespeed == true){
        sinewidth = false;
        float newspeed = ofMap(sin(ofGetElapsedTimef()), -1, 1, -5, 10);
        speed1 = newspeed + offset1;
        speed2 = newspeed + offset2;
        speed3 = newspeed + offset3;
    }
    // sinusoidal oscillation in the speed. change last two values of ofMap to change the range of oscillation.
    
    if (noise == true){
        for (int i = 0; i < nLinesGroup1; i++){
            x1[i] += speed1;
            if (x1[i] > ofGetWidth()){
                x1[i] = -1;
            }
            w1[i] = (ofMap(ofNoise(noiseseed1), 0, 1, 1, thickness1));
            noiseseed1 += 0.007;
        }
        
        for (int i = 0; i < nLinesGroup2; i++){
            x2[i] += speed2;
            if (x2[i] > ofGetWidth()){
                x2[i] = -1;
            }
            if (x2[i] > ofGetWidth()){
                x2[i] = -1;
            }
            w2[i] = (ofMap(ofNoise(noiseseed2), 0, 1, 1, thickness2));
            noiseseed2 += 0.007;
        }
        
        for (int i = 0; i < nLinesGroup3; i++){
            x3[i] += speed3;
            if (x3[i] > ofGetWidth()){
                x3[i] = -1;
            }
            w3[i] = (ofMap(ofNoise(noiseseed3), 0, 1, 1, thickness3));
            noiseseed3 += 0.007;
        }
    }
    else{
        for (int i = 0; i < nLinesGroup1; i++){
            x1[i] += speed1;
            if (x1[i] > ofGetWidth()){
                x1[i] = -1;
            }
            w1[i] = thickness1;
        }
        
        for (int i = 0; i < nLinesGroup2; i++){
            x2[i] += speed2;
            if (x2[i] > ofGetWidth()){
                x2[i] = -1;
            }
            w2[i] = thickness2;
        }
        
        for (int i = 0; i < nLinesGroup3; i++){
            x3[i] += speed3;
            if (x3[i] > ofGetWidth()){
                x3[i] = -1;
            }
            w3[i] = thickness3;
        }
    }
    // movement functions. one includes noise in the width of the lines, the other does not.
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofFill();

    if (vertical == false){
        for (int i = 0; i < nLinesGroup1; i++){
            ofSetColor(color1);
            ofDrawRectangle(x1[i], 0, w1[i], ofGetHeight());
        }
        for (int i = 0; i < nLinesGroup2; i++){
            ofSetColor(color2);
            ofDrawRectangle(x2[i], 0, w2[i], ofGetHeight());
        }
        for (int i = 0; i < nLinesGroup3; i++){
            ofSetColor(color3);
            ofDrawRectangle(x3[i], 0, w3[i], ofGetHeight());
        }
    }
    else{
        for (int i = 0; i < nLinesGroup1; i++){
            ofSetColor(color1);
            ofDrawRectangle(0, x1[i], ofGetWidth(), w1[i]);
        }
        for (int i = 0; i < nLinesGroup2; i++){
            ofSetColor(color2);
            ofDrawRectangle(0, x2[i], ofGetWidth(), w2[i]);
        }
        for (int i = 0; i < nLinesGroup3; i++){
            ofSetColor(color3);
            ofDrawRectangle(0, x3[i], ofGetWidth(), w3[i]);
        }
    }
    
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
