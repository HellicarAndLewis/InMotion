#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    bckgrndcolor = 0;
    color1 = ofColor(200, 200, 0);
    color2 = ofColor(0, 200, 200);
    color3 = ofColor(200, 0, 200);

    timeline.setup();
    timeline.setDurationInSeconds(30);
    timeline.setLoopType(OF_LOOP_NORMAL);
    timeline.addCurves("nLinesGroup1", ofRange(0, 20));
    timeline.addCurves("nLinesGroup2", ofRange(0, 20));
    timeline.addCurves("nLinesGroup3", ofRange(0, 20));
    timeline.addCurves("speed1", ofRange(-20, 20));
    timeline.addCurves("speed2", ofRange(-20, 20));
    timeline.addCurves("speed3", ofRange(-20, 20));
    timeline.addCurves("width1", ofRange(0.5, ofGetWidth()));
    timeline.addCurves("width2", ofRange(0.5, ofGetWidth()));
    timeline.addCurves("width3", ofRange(0.5, ofGetWidth()));
    timeline.addCurves("height1", ofRange(0.5, ofGetHeight()));
    timeline.addCurves("height2", ofRange(0.5, ofGetHeight()));
    timeline.addCurves("height3", ofRange(0.5, ofGetHeight()));
    
    for (int i = 0; i < 20; i++){
        x1.push_back(ofRandom(ofGetWidth()));
    }
    for (int i = 0; i < 20; i++){
        x2.push_back(ofRandom(ofGetWidth()));
    }
    for (int i = 0; i < 20; i++){
        x3.push_back(ofRandom(ofGetWidth()));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    nLinesGroup1 = timeline.getValue("nLinesGroup1");
    nLinesGroup2 = timeline.getValue("nLinesGroup2");
    nLinesGroup3 = timeline.getValue("nLinesGroup3");
    
    speed1 = timeline.getValue("speed1");
    speed2 = timeline.getValue("speed2");
    speed3 = timeline.getValue("speed3");
    
    width1 = timeline.getValue("width1");
    width2 = timeline.getValue("width2");
    width3 = timeline.getValue("width3");
    
    height1 = timeline.getValue("height1");
    height2 = timeline.getValue("height2");
    height3 = timeline.getValue("height3");
    
    for (int i = 0; i < nLinesGroup1; i++){
        x1[i] += speed1;
        if (speed1 > 0 && x1[i] > ofGetWidth()){
            x1[i] = 0 - width1;
        }
        if (speed1 < 0 && (x1[i] + width1) < 0){
            x1[i] = ofGetWidth() + width1;
        }
    }
    for (int i = 0; i < nLinesGroup2; i++){
        x2[i] += speed2;
        if (speed2 > 0 && x2[i] > ofGetWidth()){
            x2[i] = 0 - width2;
        }
        if (speed2 < 0 && (x2[i] + width2) < 0){
            x2[i] = ofGetWidth() + width2;
        }
    }
    for (int i = 0; i < nLinesGroup3; i++){
        x3[i] += speed3;
        if (speed3 > 0 && x3[i] > ofGetWidth()){
            x3[i] = 0 - width3;
        }
        if (speed3 < 0 && (x3[i] + width3) < 0){
            x3[i] = ofGetWidth() + width3;
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofFill();
    ofSetColor(bckgrndcolor);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    for (int i = 0; i < nLinesGroup1; i++){
        ofSetColor(color1);
//        if (vertical == true)
//            ofDrawRectangle((ofGetWidth()-width1)/2, x1[i], width1, height1);
//        else
            ofDrawRectangle(x1[i], (ofGetHeight()-height1)/2, width1, height1);
    }
    for (int i = 0; i < nLinesGroup2; i++){
        ofSetColor(color2);
//        if (vertical == true)
//            ofDrawRectangle((ofGetWidth()-width2)/2, x2[i], width2, height2);
//        else
            ofDrawRectangle(x2[i], (ofGetHeight()-height2)/2, width2, height2);
    }
    for (int i = 0; i < nLinesGroup3; i++){
        ofSetColor(color3);
//        if (vertical == true)
//            ofDrawRectangle((ofGetWidth()-width3)/2, x3[i], width3, height3);
//        else
            ofDrawRectangle(x3[i], (ofGetHeight()-height3)/2, width3, height3);
    }
    
    if (!hide)
        timeline.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
