#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    
    speed = 1;
    
    ofBackground(0);
    vidGrabber.setDeviceID(0);
    
    imgWidth = ofGetWidth()/3;
    imgHeight = ofGetHeight()/3;
    vidGrabber.initGrabber(imgWidth, imgHeight);
    
    slitWidth = 1;
    maxBufferSize = ofGetWidth()/slitWidth;
    
    gui.setup();
    gui.add(color.set("color", ofColor(230, 40, 230), ofColor(0,0), ofColor(255, 255)));
    gui.add(lineHeight.set("line height", 195, 0, imgHeight));
    gui.add(spacing.set("spacing", 20, 0, ofGetWidth()/2));
    
    nLines = ofGetWidth()/(lineHeight+spacing);
    
    for (int i = 0; i < nLines; i++){
        locX.push_back(0);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    nLines = ofGetWidth()/(lineHeight+spacing);

    for (int i = 0; i < nLines; i++){
        if (locX[i] == 0 || locX[i] < ofGetWidth()){
            locX[i] += speed;
        }
        else if (locX[i] == ofGetWidth() || locX[i] > ofGetWidth()){
            locX[i] = 0;
        }
    }
    
    vidGrabber.update();
    
    if (vidGrabber.isFrameNew()){
        ofImage img;
        img.allocate(imgWidth, imgHeight, OF_IMAGE_COLOR);
        img.setFromPixels(vidGrabber.getPixels());
        img.mirror(false, true);
        imgBuffer.push_front(img);
    }
    
    if (imgBuffer.size()>maxBufferSize)
        imgBuffer.pop_back();
    
    if (!cursor)
        ofShowCursor();
    
    if (cursor)
        ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (imgBuffer.size() > 0){
    
        int slitLocX = imgBuffer[0].getWidth()/2 - slitWidth/2;
        ofSetColor(color);
        
        for (int x = 0; x < imgBuffer.size(); x++){
            for (int i = 0; i < nLines; i++){
                int locY = x * slitWidth;
                imgBuffer[x].drawSubsection(locX[i] * i, locY, lineHeight, slitWidth, 0, slitLocX);
            }
        }
    }
    
    if (!hide)
        gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'h')
        hide = !hide;
    
    if (key == 'm')
        cursor = !cursor;
    
    if (key == 'f')
        ofToggleFullscreen();
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