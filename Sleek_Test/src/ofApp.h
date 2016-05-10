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
		
    int nLinesGroup1;
    int nLinesGroup2;
    int nLinesGroup3;
        // could make these into sliders
    vector<float> x1, x2, x3;
    vector<float> w1, w2, w3;
    float noiseseed1, noiseseed2, noiseseed3;
    ofxSlider<float> thickness1, thickness2, thickness3;
    ofxSlider<float> speed1, speed2, speed3;
    ofxToggle noise;
    ofxToggle vertical;
    ofxToggle lockspeeds;
    bool hide;
    ofxPanel gui;
    ofParameter<ofColor> color1;
    ofParameter<ofColor> color2;
    ofParameter<ofColor> color3;
    ofxToggle sinespeed;
    float offset1, offset2, offset3;
    
    

    ofxToggle sinewidth;
    ofxToggle randomwidths;


    ofxToggle noisewidths;
    vector<float> noiseseeds;
    float stepsize;
    


};
