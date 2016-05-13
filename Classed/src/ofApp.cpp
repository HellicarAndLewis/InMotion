#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);

    ofSetBackgroundColor(0);

    gui.setup();
    // set up panel. can give it a name as well
    gui.add(spawnrate.set("spawn rate", 0.003, 0, .6));
    // rate at which lines are drawn on screen
    gui.add(vertical.set("vertical mode", false));
    // switch to vertical scrolling
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    time = ofGetElapsedTimeMillis();
    timeSinceLastSpawnTime = time - last_spawntime;
    
    if (vertical){
        for (int i = 0; i < vRect.size(); i++){
            vRect[i].update();
            if (vRect[i].y > ofGetHeight()){
                vRect.erase(vRect.begin() + i);
            }
        }
    }
    else{
        for (int i = 0; i < hRect.size(); i++){
            hRect[i].update();
            if (hRect[i].x > ofGetWidth()){
                hRect.erase(hRect.begin() + i);
            }
        }
    }
    // remove lines from vectors if they have left the screen
}

//--------------------------------------------------------------
void ofApp::draw(){


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
        tempRect.setup(ofRandom(100, 600), 2);
        hRect.push_back(tempRect);
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
