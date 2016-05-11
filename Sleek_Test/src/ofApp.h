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
//    int screensize, smallerSize;
    bool hide;
    bool cursor;
    ofParameter<int> nLinesGroup1, nLinesGroup2, nLinesGroup3;
        // could make these into sliders
    vector<float> x1, x2, x3;
    ofParameter<int> speed1, speed2, speed3;
    ofParameter<float> width1, width2, width3;
    ofParameter<float> height1, height2, height3;
    ofParameter<bool> vertical, lockwidth, lockheight, lockspeeds, sinespeed, sinewidth, sineheight;
    ofParameter<ofColor> color1, color2, color3;
    float offset1, offset2, offset3;
    ofFbo buffer;
};
