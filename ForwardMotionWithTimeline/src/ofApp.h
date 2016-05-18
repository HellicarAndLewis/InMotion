#pragma once

#include "ofMain.h"
#include "ofxTimeline.h"
#include "moveLine.h"

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
    float speedxMax;
    float speedxMin;
    float speedyMax;
    float speedyMin;
    ofParameter <float> speedx;
    ofParameter <float> speedy;
    ofParameter <bool> sineX;
    ofParameter <bool> sineY;
    vector <moveLine> myLines;
    int numberOfLines;
    float startingX;
    float startingY;
    float lineW;
    float endingX;
    float endingY;
    float space;

};
