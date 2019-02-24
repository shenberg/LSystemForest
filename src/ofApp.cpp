
#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    lSystem.addRule(Rule('F',"FF+[F+F-]-[F-F+]"));
    // calculate our string by applying l-system to it
    std::string currentString = "F";
    for (int i = 0; i < 5; i++) {
        currentString = lSystem.applySystemOnce(currentString);
        //ofLogWarning() << "iteration " << i+1 << " output: " << currentString;
    }
    lSystemResult = currentString;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    //turtle.setPosition(ofGetWidth() / 2, ofGetHeight() / 2);
    turtle.setPosition(ofGetWidth() / 2, ofGetHeight()); // bottom of the screen
    turtle.setCurrentAngle(-PI/2); // point up
    turtle.setDistanceToTravel(6);
    turtle.setDistanceRandomness(20);
    turtle.setRotationAngle((PI/18) * (2. + ofNoise(ofGetElapsedTimef()/3.)));
    
    ofSetColor(255, 255, 255);
    turtle.draw(lSystemResult);
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
