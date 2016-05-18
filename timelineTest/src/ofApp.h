#pragma once

#include "ofMain.h"
#include "ofxTimeline.h"

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
		
    ofxTimeline timeline;
    int nLinesGroup1, nLinesGroup2, nLinesGroup3;
    vector<float> x1, x2, x3;
    float speed1, speed2, speed3;
    float width1, width2, width3;
    float height1, height2, height3;
//    bool vertical, lockwidth, lockheight, lockspeeds, sinespeed, sinewidth, sineheight;
    ofColor color1, color2, color3, bckgrndcolor;
    float offset1, offset2, offset3;
    bool hide;
};
