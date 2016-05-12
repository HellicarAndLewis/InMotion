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
    
            horizRect();
    
        private:
    
    
    };


#endif /* horizRect_h */