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
    
    void setDistanceRandomness(float randomness) {
        distanceRandomness = randomness;
    }
    
    void draw(const std::string& commands) {
        ofSeedRandom(6);
        ofPath path;
        path.setFilled(false);
        path.setStrokeWidth(1);

        path.moveTo(currentState.position);
        for (char c : commands) {
            if (c == 'F') {
                ofVec2f direction(cos(currentState.angle), sin(currentState.angle));
                currentState.position += direction * (distanceToTravel + ofRandom(0, distanceRandomness));
                path.lineTo(currentState.position);
            } else if (c == '+') {
                currentState.angle += rotationAngle;
            } else if (c == '-') {
                currentState.angle -= rotationAngle;
            } else if (c == '[') {
                splitPoints.push_back(currentState);
            } else if (c == ']') {
                currentState = splitPoints.back();
                // move back to split point without drawing a line to it
                path.moveTo(currentState.position);
                splitPoints.pop_back();
            } else {
                ofLogWarning() << "unrecognized character: " << c;
            }
        }
        
        path.draw();
    }
private:
    TurtleState currentState;
    std::vector<TurtleState> splitPoints;
    
    float distanceToTravel;
    float rotationAngle;
    float distanceRandomness;
};

#endif /* Turtle_h */
