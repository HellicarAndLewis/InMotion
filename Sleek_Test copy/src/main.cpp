#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
    
    ofGLFWWindowSettings settings;
    settings.windowMode = OF_FULLSCREEN;
    settings.multiMonitorFullScreen = true;
    ofCreateWindow(settings);
    ofRunApp(new ofApp);
//    
//    ofAppGLFWWindow window;
//    
//    window.setMultiDisplayFullscreen(true);
//	ofSetupOpenGL(&window, 1024*2, 768, OF_FULLSCREEN);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
