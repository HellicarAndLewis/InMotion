//
//  moveLine.h
//  Classed
//
//  Created by Erica Jewell on 5/12/16.
//
//

#ifndef moveLine_h
#define moveLine_h
#include "ofMain.h"

class moveLine {
    
public:
    moveLine();
    void setup(int numLines, float xStart, float yStart, float lineWidth, float xEnd, float yEnd);
    void update(float xSpeed, float ySpeed);
    void draw();

    float x_end;
    float y_end;
    int n_lines;
    float x_start;
    float y_start;
    float line_width;
    
    ofMesh mesh;
    
private:
    
    
};


#endif /* moveLine_h */