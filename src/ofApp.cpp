#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);






	ofNoFill();

	ofEnableSmoothing();
	ofEnableAlphaBlending();

	//musica.loadSound("musica.mp3");

	//musica.play();
	//play = true;
	receiver.setup(6449);

	for (int i = 0; i<512; i++) {
		coorX[i] = ofRandom(0, 1000);
		iniY[i] = ofRandom(100, 600);




	}
}

//--------------------------------------------------------------
void ofApp::update() {








	while (receiver.hasWaitingMessages())
	{
		ofxOscMessage m;
		receiver.getNextMessage(&m);

		msg = std::string("/fft_value");
		addr = std::string(m.getAddress());
		//if (addr.compare(msg) == 0) {
		if (msg == addr) {
			for (int j = 0; j < 512; j++) {


				coorY[j] = iniY[j] - m.getArgAsFloat(j) * 30;
				if (coorY[j] < 20) {
					coorY[j] = 20;
				}

			}
		}


	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	for (int j = 0; j<512; j++) {
		ofSetColor(255, 0, 0);

		//ofLine (coorX[j],coorY[j],coorX[j+1],coorY[j+1]);
		ofNoFill();


		rama(coorX[j], coorY[j], 1100 - coorY[j], j + 25);
		ofFill();
		ofSetColor(255, 255, 255, 20);

		ofCircle(coorX[j], coorY[j], 30);
		ofSetColor(255, 255, 255, 125);

		ofCircle(coorX[j], coorY[j], 10);
		ofSetColor(255, 0, 0, 225);

		ofCircle(coorX[j], coorY[j], 5);





	}
}
void ofApp::rama(int inicioX, int inicioY, int longitud, int ancho) {
	int medioX = inicioX;
	int medioY = inicioY + longitud / 2;
	int finalX = inicioX;
	int finalY = inicioY + longitud;
	int control1X = inicioX - ancho;
	int control1Y = inicioY + longitud / 4;
	int control2X = inicioX + ancho;
	int control2Y = inicioY + 3 * (longitud / 4);

	ofBeginShape();

	ofVertex(inicioX, inicioY);
	ofBezierVertex(inicioX, inicioY, control1X, control1Y, medioX, medioY);
	ofBezierVertex(medioX, medioY, control2X, control2Y, finalX, finalY);
	ofVertex(finalX, finalY);
	ofEndShape();





}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
