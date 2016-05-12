//
//  vertRect.h
//  Classed
//
//  Created by Erica Jewell on 5/12/16.
//
//

#ifndef vertRect_h
#define vertRect_h
#include "ofMain.h"

class vertRect {
    
public:
    
    void setup(float _w, float _h);
    void update();
    void draw();
    
    float x;
    float y;
    float w;
    float h;
    ofColor color1;
    ofColor color2;
    
    float speed;
    
    vertRect();
    
private:
    
    
};


#endif /* vertRect_h */