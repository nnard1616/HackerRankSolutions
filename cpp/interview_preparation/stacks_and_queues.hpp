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
            stack<int> temp;
            stack_oldest_on_top = stack<int>();
            stack_newest_on_top.push(x);
            temp = stack_newest_on_top;
            while (!stack_newest_on_top.empty()) {
                stack_oldest_on_top.push(stack_newest_on_top.top());
                stack_newest_on_top.pop();
            }
            stack_newest_on_top = temp;
        }

        void pop() {
            stack_oldest_on_top.pop();
            stack<int> temp;
            stack_newest_on_top = stack<int>();
            temp = stack_oldest_on_top;
            while (!stack_oldest_on_top.empty()) {
                stack_newest_on_top.push(stack_oldest_on_top.top());
                stack_oldest_on_top.pop();
            }
            stack_oldest_on_top = temp;
        }

        int front() {
            return stack_oldest_on_top.top();
        }
    private:

    };
}


#endif //CPP_STACKS_AND_QUEUES_HPP
