//
// Created by Nathan Nard on 12/17/18.
//

#ifndef CPP_PRACTICE_HPP
#define CPP_PRACTICE_HPP
#import <bits/stdc++.h>

using namespace std;
namespace google_application {

    string practiceSolution1(string &S, int K) {
        string result = "";

        int count = 0;

        // iterate from back to front, every K non '-' elements insert '-'
        for (auto itr = S.rbegin(); itr != S.rend(); itr++) {

            if (*itr == '-') {
                continue;
            }

            // determine if we need to insert '-'
            if ((count + 1) % K == 0) {
                result = (char)toupper(*itr) + result;

                // avoid adding '-' at start of string
                if (itr + 1 != S.rend()) {
                    result = "-" + result;
                }

            } else {
                result = (char)toupper(*itr) + result;
            }

            count++;
        }

        return result;
    }
}
#endif //CPP_PRACTICE_HPP
