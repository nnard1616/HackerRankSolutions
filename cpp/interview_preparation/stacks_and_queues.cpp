//
// Created by nnard on 10/27/21.
//

#include "stacks_and_queues.hpp"


string stacks_and_queues::isBalanced(string s) {
    stack<char> stacker;
    bool result = true;
    char top;

    for (char c : s) {
        if (c == '[' || c == '{' || c == '('){
            stacker.push(c);
        } else {
            if (!stacker.empty()) {
                top = stacker.top();
                if (c == ']' && top != '[') {
                    result = false;
                    break;
                }
                if (c == '}' && top != '{') {
                    result = false;
                    break;
                }
                if (c == ')' && top != '(') {
                    result = false;
                    break;
                }
                stacker.pop();
            } else {
                result = false;
                break;
            }
        }
    }

    if (!stacker.empty()) {
        result = false;
    }

    return result ? "YES" : "NO";
}
