//
//  horizRect.cpp
//  Classed
//
//  Created by Erica Jewell on 5/12/16.
//
//

#include "horizRect.h"

horizRect::horizRect(){
}

void horizRect::setup(float _w, float _h){
    w = _w;
    h = _h;
    x = - w;
    y = ofRandom(0, ofGetHeight());
    
    speed = ofRandom(5, 20);
    
    color1.set(200);
}


void horizRect::update(){
    color1.set(ofMap(ofDist(x, 0, ofGetWidth(), 0), w+ofGetWidth(), -w, 50, 255));
    x += speed;
}



void horizRect::draw(){
    ofSetColor(color1);
    ofDrawRectangle(x, y, w, h);
    
    // for now, only using 1 color. change this to gradient with GL
}



