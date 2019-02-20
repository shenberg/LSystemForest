//
//  Turtle.h
//  LSystemForest
//
//  Created by Roee Shenberg on 20/02/2019.
//

#ifndef Turtle_h
#define Turtle_h

#include "ofMain.h"

struct TurtleState {
    ofVec2f position;
    float angle;
};

class Turtle {
public:
    void setPosition(float x, float y) {
        currentState.position.x = x;
        currentState.position.y = y;
    }
    void setPosition(ofVec2f newPosition) {
        currentState.position = newPosition;
    }
    
    void setDistanceToTravel(float newDistance) {
        distanceToTravel = newDistance;
    }
    
    void setCurrentAngle(float angle) {
        currentState.angle = angle;
    }
    
    void setRotationAngle(float angle) {
        rotationAngle = angle;
    }
    
    void draw(std::string commands) {
        ofPath path;
        path.setFilled(false);
        path.setStrokeWidth(1);

        path.moveTo(currentState.position);
        for (char c : commands) {
            if (c == 'F') {
                ofVec2f direction(cos(currentState.angle), sin(currentState.angle));
                currentState.position += direction * distanceToTravel;
                path.lineTo(currentState.position);
            } else if (c == '+') {
                currentState.angle += rotationAngle;
            } else if (c == '-') {
                currentState.angle -= rotationAngle;
            } else {
                ofLogWarning() << "unrecognized character: " << c;
            }
        }
        
        path.draw();
    }
private:
    TurtleState currentState;
    float distanceToTravel;
    
    float rotationAngle;
};

#endif /* Turtle_h */
