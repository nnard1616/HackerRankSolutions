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

int search::pairs(int k, vector<int> arr) {

    vector<int> diffs;

    std::sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size() - 1; i++) {
        diffs.push_back(arr[i+1] - arr[i]);
    }

    int result = 0;
    int checksum = 0;
    for (int i = 0; i < diffs.size(); i++) {
        for (int j = i; j < diffs.size(); j++) {
            checksum += diffs[j];
            if (checksum == k) {
                result++;
            }
            if (checksum > k) {
                checksum = 0;
                break;
            }
        }
    }

    return result;
}

long search::triplets(vector<int> a, vector<int> b, vector<int> c) {
    long result = 0;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::sort(c.begin(), c.end());

    long pcount = 0;
    long rcount = 0;
    int prevq = -1;
    int prevp = -1;
    int prevr = -1;

    for (int q = 0; q < b.size(); q++) {

        if (b[q] == prevq) {
            continue;
        }

        for (int p = 0; p < a.size() ; p++) {
            if (a[p] == prevp) {
                continue;
            }
            if ( a[p] > b[q] ) {
                prevp = -1;
                break;
            }
            pcount++;
            prevp = a[p];
        }

        if ( pcount > 0 ) {
            for (int r = 0; r < c.size(); r++) {
                if (c[r] == prevr) {
                    continue;
                }
                if (c[r] > b[q]) {
                    prevr = -1;
                    break;
                }
                rcount++;
                prevr = c[r];
            }
        }

        result += (pcount * rcount);
        prevq = b[q];
        prevp = -1;
        prevr = -1;
        pcount = 0;
        rcount = 0;
    }


    return result;
}



long search::triplets2(vector<int> a, vector<int> b, vector<int> c) {
    long result = 0;

    sort( a.begin(), a.end());
    sort( b.begin(), b.end());
    sort( c.begin(), c.end());

    a.erase( unique(a.begin(), a.end()), a.end());
    b.erase( unique(b.begin(), b.end()), b.end());
    c.erase( unique(c.begin(), c.end()), c.end());

    long b_greater_than_a[b.size()];
    long b_greater_than_c[b.size()];

    for (int i = 0; i < b.size(); i++) {
        auto pos_a_in_b = common::binary_search_for_insertion_point(b[i], a);
        auto pos_c_in_b = common::binary_search_for_insertion_point(b[i], c);

        if (b[i] >= *(pos_a_in_b) ) {
            b_greater_than_a[i] = min((long) (pos_a_in_b - a.begin()) + 1, (long)a.size());
        } else {
            b_greater_than_a[i] = min((long) (pos_a_in_b - a.begin()) , (long)a.size());
        }

        if (b[i] >= *(pos_c_in_b) ) {
            b_greater_than_c[i] = min((long) (pos_c_in_b - c.begin()) + 1, (long)c.size());
        } else {
            b_greater_than_c[i] = min((long) (pos_c_in_b - c.begin()) , (long)c.size());
        }

    }
//    common::print_array(b_greater_than_a, b.size());
//    common::print_array(b_greater_than_c, b.size());

    for (int i = 0; i < b.size(); i++) {
        result += (b_greater_than_a[i] * b_greater_than_c[i]);
    }

    return result;
}

long search::minTime(vector<long> machines, long goal) {
    sort(machines.begin(), machines.end());

    long most_efficient = machines[0];
    long max_daycount = most_efficient * goal;
    long min_daycount = 0;
    long result = (max_daycount + min_daycount) / 2;


    // get count of each efficiency for calculating production for a given day count
    map<long, int> efficiency_counts;
    for (auto it = machines.begin(); it != machines.end(); it++) {
        try {
            efficiency_counts.at(*it);
            efficiency_counts[*it]++;
        } catch (out_of_range& e) {
            efficiency_counts[*it] = 1;
        }
    }

    long production = calc_production(efficiency_counts, result);

    // binary search
    while ( (max_daycount - min_daycount) != 1 ) {
        if ( production < goal) {
            min_daycount = result;
        } else {
            max_daycount = result;
        }

        result = (min_daycount + max_daycount) / 2;
        production = calc_production(efficiency_counts, result);

    }

    result = (calc_production(efficiency_counts, min_daycount) < goal) ? max_daycount : min_daycount;

    return result;
}

long search::calc_production(map<long, int> efficiency_counts, long day_count) {
    long production = 0;
    for (auto it = efficiency_counts.begin(); it != efficiency_counts.end(); it++) {
        production += (day_count / it->first) * it->second;
    }
    return production;
}


long search::maximumSum(vector<long> a, long m) {
    long max_mod = 0;
    long running_sum = 0;

    auto cleaned_end = remove_if(a.begin(), a.end(), [&m](long &l) {return ((l%m)==0);});

    for (auto it = a.begin(); it != cleaned_end; it++) {
        for (auto it2 = it; it2 != cleaned_end; it2++) {
            running_sum = (running_sum + *it2) % m;
            if (running_sum > max_mod) {
                max_mod = running_sum;
            }
            if ( m - 1 == max_mod) {
                return max_mod;
            }
        }
        running_sum = 0;
    }

    return max_mod;
}

// https://www.quora.com/What-is-the-logic-used-in-the-HackerRank-Maximise-Sum-problem
// this is a gotchya type problem.  The modulo arithmetic was super intersting though.
long search::maximumSum2(vector<long> a, long m) {
    long result = 0;
    long prefix[a.size()];

    int curr = 0;
    int prefix_i = 0;
    for(int i = 0; i < a.size(); i ++) {
        if (( a[i] % m ) != 0 ) {
            curr = (a[i] % m + curr) % m;
            prefix[prefix_i++] = curr;
        }
    }

    for(int i = 0; i < prefix_i; i ++) {
        for(int j = i-1; j >= 0; j --) {
            result = max(result, (prefix[i] - prefix[j] + m) % m);
        }
        result = max(result, prefix[i]); // Don't forget sum from beginning.
    }

    return result;
}

bool fncomp (pair<long,long> lhs, pair<long,long> rhs) {
    if (lhs.first<rhs.first)
        return true;
    if (lhs.first==rhs.first)
        return lhs.second<rhs.second;
    return false;
}

long search::maximumSum3(vector<long> a, long m) {
    long result = 0;
    pair<long,long> prefix[a.size()];
    set<int> indicies_present;
    long curr = 0;
    int prefix_i = 0;

    // compute the prefix sums first
    for(int i = 0; i < a.size(); i ++) {
        if (( a[i] % m ) != 0 ) {
            curr = (a[i] % m + curr) % m;
            prefix[prefix_i] = pair<long,long>(curr,prefix_i);
            //used to keep track of prefix sums available for subtracting from latter prefix sums
            indicies_present.insert(prefix_i);
            prefix_i++;

        }
    }

    sort(prefix, prefix+prefix_i, fncomp);
    result = prefix[prefix_i-1].first;


    long candidate ;
    for(int p1 = 0; p1 < prefix_i; p1++) {
        // keep track of which sums are available to subtract
        indicies_present.erase(prefix[p1].second);
        if (*(indicies_present.begin()) < prefix[p1].second){
            for (int p2 = p1 +  1; p2 < prefix_i; p2++) {
                // can only subtract prefix sums that occurred previously in the original prefix sum array
                if (prefix[p1].second > prefix[p2].second) {
                    candidate = (prefix[p1].first - prefix[p2].first + m) % m;
                    // if the candidate is smaller than the current largest modulus, then there's no way incrementing
                    // the second pointer will get us a bigger better result as incremeing the second pointer will only
                    // make the subsequent candidates smaller.
                    if (candidate < result) {
                        break;
                    }
                    result = candidate;
                    if (result == m - 1) {
                        return result;
                    }
                }
            }
        }
    }
    return result;
}

long search::maximumSum4(vector<long> a, long m) {
    long result = 0;
    set<pair<long,long>, bool(*)(pair<long,long>,pair<long,long>)> prefix(fncomp);
    long curr = 0;
    for(int i = 0; i < a.size(); i ++) {
        curr = (a[i] % m + curr) % m;
        prefix.insert(pair<long,long>(curr,i));
    }
    result = (prefix.end()--)->first;


    long candidate ;
    for(auto p1 = prefix.begin(); p1 != prefix.end(); p1++) {
        for (auto p2 = p1; p2 != prefix.end(); p2++) {
            if (p1->second > p2->second) {
                candidate = ( p1->first - p2->first  + m ) % m;
                if (candidate < result) {
                   break;
                }
                result = candidate;
            }
        }
    }
    return result;
}

