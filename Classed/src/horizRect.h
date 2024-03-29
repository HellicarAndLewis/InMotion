//
//  horizRect.h
//  Classed
//
//  Created by Erica Jewell on 5/12/16.
//
//

#ifndef horizRect_h
#define horizRect_h
#include "ofMain.h"

    class horizRect {
    
        public:
    
            void setup(float _w, float _h, float minSpeed, float maxSpeed);
            void update(ofColor yourColor1, ofColor yourColor2);
            void draw();
    
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
    
            horizRect();
    
        private:
    
    
    };


#endif /* horizRect_h */