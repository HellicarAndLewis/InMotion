//
//  ofxGuiColorPalette.cpp
//  ofxGuiColorPicker
//
//  Created by Erica Jewell on 5/16/16.
//
//

#include "ofxGuiColorPalette.h"

ofxGuiColorPalette::ofxGuiColorPalette(){
    
}

void ofxGuiColorPalette::setup(string fileName){
    paletteImage.load(fileName);

}
// loads the image file for the palette from the bin folder




void ofxGuiColorPalette::update(float mouseX, float mouseY){
    if (mouseX > x && mouseX < x+w){
        if (mouseY > y && mouseY < y+h){
            _red = ofMap(mouseX, x, x+w, 0, 255);
            _blue = ofMap(mouseY, y, y+h, 0, 255);
            _green = ofMap(mouseY, y, y+h, 255, 0);
        }
    }
}
// put this in mousePressed




void ofxGuiColorPalette::draw(float _x, float _y, float _w, float _h){
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    ofFill();
    ofSetColor(255);
    paletteImage.draw(_x, _y, _w, _h);
    
}