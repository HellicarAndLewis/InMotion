#include "ofApp.h"
#define OUTPUT_WIDTH 1920
#define OUTPUT_HEIGHT 1080
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    vidGrabber.setDeviceID(0);
//    vidGrabber.setDesiredFrameRate(60);
    
    imgWidth = ofGetWidth()/3;
    imgHeight = ofGetHeight()/3;
    vidGrabber.initGrabber(imgWidth, imgHeight);
    
    slitWidth = 1;
    maxBufferSize = ofGetWidth()/slitWidth;
    
    gui.setup();
    gui.add(color.set("color", ofColor(255, 40, 20), ofColor(0,0), ofColor(255, 255)));
    gui.add(lineHeight.set("line height", 50, 0, imgHeight));
    gui.add(spacing.set("spacing", 20, 0, ofGetHeight()/2));
    gui.add(yTranslate.set("translate - y", 0, -5, 5));
    gui.add(stagger.set("stagger", false));
    
    buffer.allocate(OUTPUT_WIDTH, OUTPUT_HEIGHT);
    
    ofBackground(100);
}


//--------------------------------------------------------------
void ofApp::update(){
    
    nLines = ofGetHeight()/(lineHeight+spacing);

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
    buffer.begin();
    ofPushStyle();
    ofSetColor(0);
    ofDrawRectangle(0, 0, OUTPUT_WIDTH, OUTPUT_HEIGHT);
    ofPushMatrix();
    if (imgBuffer.size()>0){
        
        int slitLocX = imgBuffer[0].getWidth()/2 - slitWidth/2;
        ofSetColor(color);
        // change this to color the video
        
        for (int x = 0; x < imgBuffer.size(); x++){
            for (int i = 0; i < nLines; i++){
                if (spacing + (lineHeight + spacing) * i < ofGetHeight() - spacing){
                    int locX = x * slitWidth;
                    ofTranslate(0, yTranslate);
                    if (!stagger){
                        imgBuffer[x].drawSubsection(locX, spacing + (lineHeight + spacing) * i, slitWidth, lineHeight, slitLocX, 0);
                    }
                    else {
                        imgBuffer[x].drawSubsection(locX * (i+1), spacing + (lineHeight + spacing) * i, slitWidth, lineHeight, slitLocX, 0);
                    }
                }
            }
        }
    }
    ofPopMatrix();
    buffer.end();
    buffer.draw(ofGetScreenWidth(), 0);
    buffer.draw(ofGetScreenWidth()/2 - OUTPUT_WIDTH/4, ofGetScreenHeight()/2 - OUTPUT_HEIGHT/4, OUTPUT_WIDTH/2, OUTPUT_HEIGHT/2);
    
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
