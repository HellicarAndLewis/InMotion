#include "ofApp.h"

int palette_x = 100;
int palette_y = 40;
int palette_w = 200;
int palette_h = 200;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(200);
    gui.setup();
    gui.setPosition(palette_x, 20 + palette_y + palette_h);
    gui.add(color.set("refine color (hold q)", ofColor(242, 114, 3), ofColor(0,0), ofColor(255, 255)));
    gui.minimizeAll();
    palette.setup("paletteImage.png");
    palette._red = 242;
    palette._green = 114;
    palette._blue = 3;
    // allocates image file for palette
}

//--------------------------------------------------------------
void ofApp::update(){
    
    color = ofColor(palette._red, palette._green, palette._blue);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    palette.draw(palette_x, palette_y, palette_w, palette_h);
    // draw palette at x, y, width, height
    gui.draw();
    
    ofFill();
    ofSetColor(palette._red, palette._green, palette._blue);
    ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/4, ofGetWidth()/3, ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 'q'){
        palette._red = color->r;
        palette._green = color->g;
        palette._blue = color->b;
    }
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

    palette.update(mouseX, mouseY);
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
