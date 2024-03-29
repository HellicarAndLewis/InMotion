#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxSlider.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    int xloc;
    int yloc;
    int frame;
    bool hide;
    bool cursor;
    ofxPanel gui;
    ofParameter<ofColor> color1;
    ofParameter<ofColor> color2;
    ofxSlider<float> speed;
    ofxSlider<float> width1;
    ofxSlider<float> width2;
    ofxToggle sinewidth;
    ofxToggle randomwidths;
    ofxToggle lockwidths;
    ofxToggle vertical;
    ofxToggle sinespeed;
    ofxToggle noisewidths;
    vector<float> noiseseeds;
    float stepsize;
};

