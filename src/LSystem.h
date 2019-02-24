//
//  LSystem.h
//  LSystemForest
//
//  Created by Roee Shenberg on 20/02/2019.
//

#ifndef LSystem_h
#define LSystem_h

#include <string>
#include <sstream>
#include <vector>

#include "Rule.h"

class LSystem {
public:
    void addRule(Rule rule) {
        rules.push_back(rule);
    }

    std::string applySystemOnce(const std::string& input) {
        std::stringstream output;
        Rule blah('a', "aaa");
        for (char c : input) {
            bool matched = false;
            // check if c matches rules
            for (Rule &rule : rules) {
                if (rule.matches(c)) {
                    output << rule.translation;
                    matched = true;
                    break;
                }
            }
            if (!matched) {
                output << c;
            }
        }
        return output.str();
    }
private:
    std::vector<Rule> rules;
};

#endif /* LSystem_h */
