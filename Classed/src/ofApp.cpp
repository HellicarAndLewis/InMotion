#include "ofApp.h"
#define OUTPUT_WIDTH 1920
#define OUTPUT_HEIGHT 1080

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);

    ofSetBackgroundColor(0);

    gui.setup();
    // set up panel. can give it a name as well
    gui.add(spawnrate.set("spawn rate", 0.003, 0, .6));
    // rate at which lines are drawn on screen
    gui.add(myColor1.set("color 1", ofColor(242, 114, 3), ofColor(0,0), ofColor(255, 255)));
    gui.add(myColor2.set("color 2", ofColor(14, 222, 229), ofColor(0,0), ofColor(255, 255)));
    gui.add(speedMin.set("speed min", 5, 1, 30));
    gui.add(speedMax.set("speed max", 20, 5, 50));
    gui.add(vertical.set("vertical mode", false));
    // switch to vertical scrolling
    
    hide = false;
    // start with the GUI visible
    
    cursor = true;
    // start with cursor visible
    
    buffer.allocate(OUTPUT_WIDTH, OUTPUT_HEIGHT);
    
    ofBackground(50);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    time = ofGetElapsedTimeMillis();
    timeSinceLastSpawnTime = time - last_spawntime;
    
    if (vertical){
        for (int i = 0; i < vRect.size(); i++){
            vRect[i].update(myColor1, myColor2);
            if (vRect[i].y > ofGetHeight()){
                vRect.erase(vRect.begin() + i);
            }
        }
    }
    else{
        for (int i = 0; i < hRect.size(); i++){
            hRect[i].update(myColor1, myColor2);
            if (hRect[i].x > ofGetWidth()){
                hRect.erase(hRect.begin() + i);
            }
        }
    }
    // remove lines from vectors if they have left the screen
    
    if (!cursor)
        ofHideCursor();
    else
        ofShowCursor();
    // show cursor
}

//--------------------------------------------------------------
void ofApp::draw(){
    buffer.begin();
    ofPushStyle();
    ofSetColor(0);
    ofDrawRectangle(0, 0, OUTPUT_WIDTH, OUTPUT_HEIGHT);
    int howmany = timeSinceLastSpawnTime * spawnrate;
    // number of lines to be drawn on screen
    for (int i = 0; i < howmany; i++){
        spawn();
        if (howmany > 0){
            last_spawntime = time;
        }
    }
    
    if (vertical){
        for (int i = 0; i < vRect.size(); i++){
            vRect[i].draw();
        }
    }
    else{
        for (int i = 0; i < hRect.size(); i++){
            hRect[i].draw();
        }
    }
    buffer.end();
    buffer.draw(ofGetScreenWidth(), 0);
    buffer.draw(ofGetScreenWidth()/2 - OUTPUT_WIDTH/4, ofGetScreenHeight()/2 - OUTPUT_HEIGHT/4, OUTPUT_WIDTH/2, OUTPUT_HEIGHT/2);

    if (!hide){
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::spawn(){
    

    if (vertical){
        vertRect tempRect;
        tempRect.setup(ofRandom(100, 600), 2);
        vRect.push_back(tempRect);
    }

    else{
        horizRect tempRect;
        tempRect.setup(ofRandom(100, 600), 2, speedMin, speedMax);
        hRect.push_back(tempRect);
    }
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
