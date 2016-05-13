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
    y = - w;
    
    speed = ofRandom(5, 20);
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    mesh.addVertex( ofPoint(x, y) );
    mesh.addColor(color1);
    mesh.addVertex( ofPoint(x, w) );
    mesh.addColor(color1);
    mesh.addVertex( ofPoint(h, y) );
    mesh.addColor(color2);
    mesh.addVertex( ofPoint(h, w) );
    mesh.addColor(color2);
}


void vertRect::update(ofColor yourColor1, ofColor yourColor2){
    
    color1.set(yourColor1.r, yourColor1.g, yourColor1.b);
    color2.set(yourColor2.r, yourColor2.g, yourColor2.b);
    _color.set(ofMap(ofDist(y, 0, ofGetHeight(), 0), w+ofGetHeight(), -w, color1.r, color2.r), ofMap(ofDist(y, 0, ofGetHeight(), 0), w+ofGetHeight(), -w, color1.g, color2.g), ofMap(ofDist(y, 0, ofGetHeight(), 0), w+ofGetHeight(), -w, color1.b, color2.b));
    _2color.set(ofMap(ofDist(y, 0, ofGetHeight(), 0), w+ofGetWidth(), -w, color1.r, color2.r), ofMap(ofDist(y, 0, ofGetHeight(), 0), w+ofGetHeight(), -w, color1.g, color2.g), ofMap(ofDist(y, 0, ofGetHeight(), 0), w+ofGetHeight(), -w, color1.b, color2.b));
    y += speed;
}


void vertRect::draw(){
    
    mesh.setColor(0, _2color);
    mesh.setColor(1, _2color);
    mesh.setColor(2, _color);
    mesh.setColor(3, _color);
    mesh.setVertex(0, ofPoint(x, y));
    mesh.setVertex(1, ofPoint(x, y+w));
    mesh.setVertex(2, ofPoint(x+h, y));
    mesh.setVertex(3, ofPoint(x+h, y+w));
    mesh.draw();
}