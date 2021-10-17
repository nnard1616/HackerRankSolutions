//
// Created by Nathan Nard on 12/23/18.
//

#ifndef CPP_SEARCH_HPP
#define CPP_SEARCH_HPP
#include <bits/stdc++.h>
#include "../common/common.hpp"

using namespace std;

namespace search{

    struct Node{
        int id;
        int parent;
        int left;
        int right;
        int depth;
        Node(){
            id = -1;
        }
        Node(int id){
            this->id = id;
        }
    };

    struct binaryTree{
        unordered_map<int, Node> theNodes;
        unordered_map<int, vector<int>> levels;
        int maxDepth;

        int numberOfNodes;
        explicit binaryTree(vector<vector<int>>& nodes){

            numberOfNodes = 1;
            maxDepth = 1;

            // initialize the nodes
            for (auto& n : nodes){
                theNodes[numberOfNodes] = Node(numberOfNodes);
                numberOfNodes++;
            }

            // initialize the nodes connectivity
            theNodes[1].parent = -1;
            theNodes[1].depth = 1;
            levels[1].push_back(1);

            for (int i = 0; i < nodes.size(); i++){
                theNodes[i+1].left = nodes[i][0];
                theNodes[i+1].right = nodes[i][1];

                if (theNodes[i+1].left != -1){
                    theNodes[theNodes[i+1].left].parent = i+1;
                    theNodes[theNodes[i+1].left].depth = theNodes[i+1].depth +1;
                    levels[theNodes[theNodes[i+1].left].depth].push_back(theNodes[i+1].left);
                    maxDepth = max(maxDepth, theNodes[theNodes[i+1].left].depth);
                }

                if (theNodes[i+1].right != -1){
                    theNodes[theNodes[i+1].right].parent = i+1;
                    theNodes[theNodes[i+1].right].depth = theNodes[i+1].depth +1;
                    levels[theNodes[theNodes[i+1].right].depth].push_back(theNodes[i+1].right);
                    maxDepth = max(maxDepth, theNodes[theNodes[i+1].right].depth);
                }
            }
        }

        void reverseChildren(int node){
            int temp = theNodes[node].left;
            theNodes[node].left = theNodes[node].right;
            theNodes[node].right = temp;
        }

        vector<int> inOrderTraversal(){
            vector<int> result;
            vector<int> stack;
            stack.push_back(1);
            unordered_map<int, int> visited;

            int node;
            while (!stack.empty()){
                node = stack.back();

                if (visited[node] == 0) {
                    visited[node] = 1;

                    if (theNodes[node].left != -1) {
                        stack.push_back(theNodes[node].left);
                        continue;
                    }
                }

                if (visited[node] == 1){
                    visited[node] = 2;
                    result.push_back(node);

                    if (theNodes[node].right != -1){
                        stack.push_back(theNodes[node].right);
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
    };

    /* Hash Tables: Ice Cream Parlor
     * https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search
     */
    void whatFlavors(vector<int> cost, int money);

    /* Swap Nodes [Algo]
     * https://www.hackerrank.com/challenges/swap-nodes-algo/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search&h_r=next-challenge&h_v=zen
     */
    vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries);

    vector<int> inOrderTraversal(vector<vector<int>>& in);

    /*
     * https://www.hackerrank.com/challenges/pairs/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search
     * @param k
     * @param arr
     * @return
     */
    int pairs(int k, vector<int> arr);

    /**
     * https://www.hackerrank.com/challenges/triple-sum/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search&h_r=next-challenge&h_v=zen
     */
    long triplets(vector<int> a, vector<int> b, vector<int> c);
    long triplets2(vector<int> a, vector<int> b, vector<int> c);

    /**
     *
     * @param machines
     * @param goal
     * @return
     */
    long minTime(vector<long> machines, long goal);

    long calc_production(map<long, int> efficiency_counts, long day_count);
}
#endif //CPP_SEARCH_HPP
