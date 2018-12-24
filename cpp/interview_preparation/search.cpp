//
// Created by Nathan Nard on 12/23/18.
//

#include "search.hpp"

void search::whatFlavors(vector<int> cost, int money) {

    unordered_map<int, int> seenSoFar;

    int query;

    for (int i = 0; i < cost.size(); i++){
        query = money - cost[i];
        if (seenSoFar[query] >= 1 && seenSoFar[query] <= cost.size()) {
            cout << seenSoFar[query] << " " << i + 1 << endl;
            return;
        } else {
            seenSoFar[cost[i]] = i+1;
        }
    }
}

vector<vector<int>> search::swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> result;

    binaryTree t(indexes);

    for (auto& k : queries){
        for (int i = k; i <= t.maxDepth; i+=k ){
            for (auto& i : t.levels[i]){
                t.reverseChildren(i);
            }
        }
        result.push_back(t.inOrderTraversal());
    }



    return result;
}

vector<int> search::inOrderTraversal(vector<vector<int>> &in) {
    vector<int> result;
    vector<int> stack;
    stack.push_back(1);
    unordered_map<int, int> visited;

    int node = 1, index = 0;
    while (!stack.empty()){
        node = stack.back();
        index = node-1;

        if (visited[node] == 0) {
            visited[node] = 1;

            if (in[index][0] != -1) {
                stack.push_back(in[index][0]);
                continue;
            }
        }

        if (visited[node] == 1){
            visited[node] = 2;
            result.push_back(node);

            if (in[index][1] != -1){
                stack.push_back(in[index][1]);
                continue;
            } else{
                stack.pop_back();
                continue;
            }
        }

        if (visited[node] == 2){
            stack.pop_back();
        }
    }

    return result;
}
