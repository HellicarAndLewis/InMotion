//
//  Rectangle.h
//  Classed
//
//  Created by Erica Jewell on 5/12/16.
//
//  Possibly work on using this class for both vertical and horizontal lines
//


#ifndef Rectangle_h
#define Rectangle_h
#include "ofMain.h"

class Rectangle {
    
public:
    
    void setup(float _w, float _h, float minSpeed, float maxSpeed);
    void update(ofColor yourColor1, ofColor yourColor2);
    void draw();
    void switchvertices();
    
    float x;
    float y;
    float w;
    float h;
    ofColor color1;
    ofColor color2;
    ofColor _color;
    ofColor _2color;
    ofMesh mesh;
    
    float speed;
    float minSpeed;
    float maxSpeed;
    
    Rectangle();
    
private:
    
};


#endif /* Rectangle_h */