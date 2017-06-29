#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();


		
		void rama(int inicioX, int inicioY, int longitud, int ancho);


		int snapCounter;
		ofImage imagen;
		



		bool play;
		float coorX[512];
		float coorY[512];
		float iniY[512];
		float value[512];




		ofxOscReceiver	receiver;
		std::string msg;
		std::string addr;
		














		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
