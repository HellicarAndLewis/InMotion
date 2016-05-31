//
//  moveLine.cpp
//  Classed
//
//  Created by Erica Jewell on 5/12/16.
//
//

#include "moveLine.h"

moveLine::moveLine(){
}

void moveLine::setup(int numLines, float xStart, float yStart, float lineWidth, float xEnd, float yEnd){

    y_end = yEnd;
    x_end = xEnd;
    n_lines = numLines;
    x_start = xStart;
    y_start = yStart;
    line_width = lineWidth;

    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    mesh.addVertex( ofPoint(x_start, y_start) );
    mesh.addColor(250);
    mesh.addVertex( ofPoint(x_start + line_width, y_start) );
    mesh.addColor(250);
    mesh.addVertex( ofPoint(x_end, y_end) );
    mesh.addColor(250);
    mesh.addVertex( ofPoint(x_end + line_width, y_end) );
    mesh.addColor(250);
    
}


void moveLine::update(float xSpeed, float ySpeed){

    x_end += xSpeed;
    y_end += ySpeed;
}



void moveLine::draw(){

    mesh.setVertex(0, ofPoint(x_start, y_start));
    mesh.setVertex(1, ofPoint(x_start + line_width, y_start));
    mesh.setVertex(2, ofPoint(x_end, y_end));
    mesh.setVertex(3, ofPoint(x_end + line_width, y_end));
    mesh.draw();

}

