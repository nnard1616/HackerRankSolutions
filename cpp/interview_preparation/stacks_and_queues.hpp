//
// Created by nnard on 10/27/21.
//

#ifndef CPP_STACKS_AND_QUEUES_HPP
#define CPP_STACKS_AND_QUEUES_HPP
#include <bits/stdc++.h>
#include "../common/common.hpp"

using namespace std;

namespace stacks_and_queues{

    string isBalanced(string s);

    class MyQueue {

    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;
        void push(int x) {
            stack_newest_on_top.push(x);
        }

        void pop() {
            if (stack_oldest_on_top.empty()) {
                transfer();
            }
            stack_oldest_on_top.pop();
        }

        int front() {
            if (stack_oldest_on_top.empty()) {
                transfer();
            }
            return stack_oldest_on_top.top();
        }
    private:
        void transfer() {
            while (!stack_newest_on_top.empty()) {
                stack_oldest_on_top.push(stack_newest_on_top.top());
                stack_newest_on_top.pop();
            }
        }
    };

    long largestRectangle(vector<int> h);
}


#endif //CPP_STACKS_AND_QUEUES_HPP
