#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    lSystem.addRule(Rule('F',"+F[+F]+F--F"));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    turtle.setPosition(ofGetWidth() / 2, ofGetHeight() / 2);
    turtle.setCurrentAngle(0);
    turtle.setDistanceToTravel(3);
    turtle.setRotationAngle(0.5 + 0.5*sin(ofGetElapsedTimef() / 5));
    
    ofSetColor(255, 255, 255);
    std::string currentString = "F";
    for (int i = 0; i < 5; i++) {
        currentString = lSystem.applySystemOnce(currentString);
        //ofLogWarning() << "iteration " << i+1 << " output: " << currentString;
    }
    turtle.draw(currentString);
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
