//
//  Rule.h
//  LSystemForest
//
//  Created by Roee Shenberg on 20/02/2019.
//

#ifndef Rule_h
#define Rule_h

#include <string>

class Rule {
public:
    Rule(char searchChar, std::string replacementString)
        : translation(replacementString), searchCharacter(searchChar)
    {
    }

    bool matches(char ch) {
        if (ch == searchCharacter) {
            return true;
        } else {
            return false;
        }
    }

    const std::string translation;
private:
    char searchCharacter;
};

#endif /* Rule_h */
