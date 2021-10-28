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

//https://www.youtube.com/watch?v=ZmnqCZp9bBs&list=PLrmLmBdmIlptv-uwAgP8k5pGdlHedncq1
long stacks_and_queues::largestRectangle(vector<int> h) {
    long result = 0;
    stack<int> cache;
    int top, i;

    for (i = 0; i < h.size(); i++) {
        if (cache.empty()) {
            cache.push(i);
            continue;
        }
        if (h[i] >= h[cache.top()]) {
            cache.push(i);
        } else {
            while ( !cache.empty() && h[i] < h[cache.top()] ) {
                top = cache.top();
                cache.pop();
                if ( cache.empty() ) {
                    result = max(result, (long) h[top] * (i ));
                } else {
                    result = max(result, (long) h[top] * (i - cache.top()  - 1));
                }
            }
            cache.push(i);
        }
    }

    while ( !cache.empty()) {
        top = cache.top();
        cache.pop();
        if ( cache.empty() ) {
            result = max(result, (long) h[top] * (i ));
        } else {
            result = max(result, (long) h[top] * (i - cache.top()  - 1));
        }
    }

    return result;
}
