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

vector<long> stacks_and_queues::riddle(vector<long> arr) {
    long max_of_w_min = 0;
    long min_overall;
    unsigned long n = arr.size();
    long min_memo[n];
    vector<long> result;

    for (int i = 0; i < n; i++) {
        min_memo[i] = arr[i];
        max_of_w_min = max(max_of_w_min, arr[i]);
        min_overall = min(min_overall, arr[i]);
    }
    result.push_back(max_of_w_min);

    for (int w = 2; w < n + 1; w++) {
        max_of_w_min = 0;
        for (int i = 0; i < n - w + 1; i++) {
            min_memo[i] = min(arr[i+w-1], min_memo[i]);
            max_of_w_min = max(max_of_w_min, min_memo[i]);
        }
        result.push_back(max_of_w_min);

    }

    return result;
}
