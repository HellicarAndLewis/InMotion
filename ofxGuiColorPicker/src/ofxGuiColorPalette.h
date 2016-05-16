//
//  ofxGuiColorPalette.h
//  ofxGuiColorPicker
//
//  Created by Erica Jewell on 5/16/16.
//
//

#ifndef ofxGuiColorPalette_h
#define ofxGuiColorPalette_h

#include "ofxBaseGui.h"
#include "ofMain.h"


class ofxGuiColorPalette {
    
public:
    
    ofxGuiColorPalette();
    void setup(string fileName);
    void update(float mouseX, float mouseY);
    void draw(float _x, float _y, float _w, float _h);
    
    float x, y, w, h;
    ofImage paletteImage;
    float _red, _blue, _green;

};


#endif /* ofxGuiColorPalette_h */
