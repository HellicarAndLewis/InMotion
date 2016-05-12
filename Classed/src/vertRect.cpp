//
//  vertRect.cpp
//  Classed
//
//  Created by Erica Jewell on 5/12/16.
//
//

#include "vertRect.h"

vertRect::vertRect(){
}

void vertRect::setup(float _w, float _h){
    w = _w;
    h = _h;
    x = ofRandom(0, ofGetWidth());
    y = - h;
    
    speed = ofRandom(5, 20);
    
    color1.set(200);
}


void vertRect::update(){
    color1.set(ofMap(ofDist(y, 0, ofGetHeight(), 0), h+ofGetHeight(), -h, 50, 255));
    y += speed;
}



void vertRect::draw(){
    ofSetColor(color1);
    ofDrawRectangle(x, y, h, w);
    
    // for now, only using 1 color. change this to gradient with GL
}