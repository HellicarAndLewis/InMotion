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
    
    ofxPanel gui;
    int screensize;
    bool hide;
    bool cursor;
    int nLinesGroup1, nLinesGroup2, nLinesGroup3;
        // could make these into sliders
    vector<float> x1, x2, x3;
    ofxSlider<float> thickness1, thickness2, thickness3;
    ofxSlider<float> speed1, speed2, speed3;
    ofxToggle vertical;
    ofxToggle lockspeeds;
    ofxToggle lockthickness;
    ofxToggle sinespeed;
    ofxToggle sinethickness;
    ofParameter<ofColor> color1;
    ofParameter<ofColor> color2;
    ofParameter<ofColor> color3;
    float offset1, offset2, offset3;
    
    

//    ofxToggle sinewidth;
//    ofxToggle randomwidths;
//
//
//    ofxToggle noisewidths;
//    vector<float> noiseseeds;
//    float stepsize;
    


};
