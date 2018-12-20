//
// Created by Nathan Nard on 12/19/18.
//

#ifndef CPP_PRIORITY_DEQUE_HPP
#define CPP_PRIORITY_DEQUE_HPP
#include <bits/stdc++.h>
#include "../common/common.hpp"


namespace common {

    template<class Comparable>
    class Priority_Deque {
    private:
        int maxSize;
        deque<Comparable> unsortedOrder;
        vector<Comparable> sortedOrder;

    public:

        Priority_Deque(int maxSize){
            this->maxSize = maxSize;
        }

        void enqueue (Comparable in) {

            if (unsortedOrder.size() < maxSize) {

                // insert at back
                unsortedOrder.push_back(in);
                sortedOrder.insert(common::binary_search(in, sortedOrder), in);

            } else {
                // erase head
                dequeue();

                // insert at back
                unsortedOrder.push_back(in);
                sortedOrder.insert(common::binary_search(in, sortedOrder), in);
            }
        }

        bool dequeue () {
            Comparable toBeErased = unsortedOrder[0];
            sortedOrder.erase(common::binary_search(toBeErased, sortedOrder));
            // next line causes a segfault??
            // SIGILL (signal SIGILL: illegal instruction operand)
            // Process finished with exit code 132 (interrupted by signal 4: SIGILL)
            unsortedOrder.pop_front(); // <-- this fucker!
        }

        typename deque<Comparable>::iterator begin() {
            return unsortedOrder.begin();
        }

        typename deque<Comparable>::iterator end() {
            return unsortedOrder.end();
        }

        typename deque<Comparable>::iterator rbegin() {
            return unsortedOrder.rbegin();
        }

        typename deque<Comparable>::iterator rend() {
            return unsortedOrder.rend();
        }

        Comparable operator[] (int i) {
            return unsortedOrder[i];
        }

        float median() {
            float result;
            if (sortedOrder.size() % 2 == 0){
                result = (sortedOrder[sortedOrder.size()/2] + sortedOrder[sortedOrder.size()/2-1])/2.0;
            } else{
                result = sortedOrder[sortedOrder.size()/2];
            }
            return result;
        }
    };
}

#endif //CPP_PRIORITY_DEQUE_HPP
