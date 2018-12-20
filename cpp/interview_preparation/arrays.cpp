//
// Created by Nathan Nard on 12/2/18.
//

#include "arrays.hpp"

long Arrays::arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> memTable(n,0);

    long result = INT64_MIN;

    int p, q, a;

    for (auto& query : queries){ //only account for transitions, results in O(n) performance
        p = query[0];
        q = query[1];
        a = query[2];

        memTable[p] += a;


        if ((q+1) <= n) memTable[q+1] -= a;
    }

    long sum = 0;
    for (int i = 1; i <= n; i++){
        sum += memTable[i];
        if (result < sum) result = sum;
    }

    return result;


}

int Arrays::arrayManipMain() {
//    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp = "10 3\n1 5 3\n4 8 7\n6 9 1";

    stringstream ss;
    ss << nm_temp;

    getline(ss, nm_temp);

    vector<string> nm = common::split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            ss >> queries[i][j];
        }

        ss.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    for (auto& i : queries){
        common::print_container(i);
    }
    cout << result << "\n";

    return 0;
}
