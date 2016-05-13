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
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    mesh.addVertex( ofPoint(x, y) );
    mesh.addColor(color1);
    mesh.addVertex( ofPoint(x, h) );
    mesh.addColor(color1);
    mesh.addVertex( ofPoint(w, y) );
    mesh.addColor(color2);
    mesh.addVertex( ofPoint(w, h) );
    mesh.addColor(color2);
}


void horizRect::update(ofColor yourColor1, ofColor yourColor2){
    
    color1.set(yourColor1.r, yourColor1.g, yourColor1.b);
    color2.set(yourColor2.r, yourColor2.g, yourColor2.b);
    _color.set(ofMap(ofDist(x, 0, ofGetWidth(), 0), w+ofGetWidth(), -w, color1.r, color2.r), ofMap(ofDist(x, 0, ofGetWidth(), 0), w+ofGetWidth(), -w, color1.g, color2.g), ofMap(ofDist(x, 0, ofGetWidth(), 0), w+ofGetWidth(), -w, color1.b, color2.b));
    _2color.set(ofMap(ofDist(x, 0, ofGetWidth(), 0), w+ofGetWidth(), -w, color1.r, color2.r), ofMap(ofDist(x, 0, ofGetWidth(), 0), w+ofGetWidth(), -w, color1.g, color2.g), ofMap(ofDist(x, 0, ofGetWidth(), 0), w+ofGetWidth(), -w, color1.b, color2.b));
    x += speed;
}


void horizRect::draw(){
    
    mesh.setColor(0, _color);
    mesh.setColor(1, _color);
    mesh.setColor(2, _2color);
    mesh.setColor(3, _2color);
    mesh.setVertex(0, ofPoint(x, y));
    mesh.setVertex(1, ofPoint(x, y+h));
    mesh.setVertex(2, ofPoint(x+w, y));
    mesh.setVertex(3, ofPoint(x+w, y+h));
    mesh.draw();
    
}



