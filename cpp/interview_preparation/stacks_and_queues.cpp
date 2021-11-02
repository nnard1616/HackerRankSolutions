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

// dynamic programming approach
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

// https://programs.programmingoneonone.com/2021/03/hackerrank-min-max-riddle-solution.html
vector<long> stacks_and_queues::riddle2(vector<long> arr) {
    stack<int> s;
    int i;
    int n = arr.size();
    long left[n],right[n],ans[n], len;
    unordered_map<long, long> m, m_inv;

    for(i=0;i<n;++i) {
        m[arr[i]] = 0;
        ans[i] = 0;
        left[i]=-1,right[i]=n;
    }

    for(i=0;i<n;++i) {
        while(!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if(!s.empty()) {
            left[i]=s.top();
        }
        s.push(i);
    }

    while(!s.empty()) {
        s.pop();
    }

    for(i=n-1;i>=0;--i) {
        while(!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if(!s.empty()) {
            right[i]=s.top();
        }
        s.push(i);
    }

    memset(ans, 0, sizeof ans);
    for(i=0;i<n;++i) {
        len = right[i]-left[i]-1;
        ans[len-1]=max(ans[len-1], arr[i]);
    }

    for(i=n-2;i>=0;--i) {
        ans[i]=max(ans[i], ans[i+1]);
    }

    vector<long> result(ans, ans + n);

    return result;
}

int stacks_and_queues::minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int n = grid.size();
    int i_grid[n][n];

    int i = 0;
    int j = 0;
    for (const string &s : grid) {
        j = 0;
        for (const char &c : s) {
            i_grid[i][j] = (c == '.') ? n*n : -1;
            j++;
        }
        i++;
    }

    stack<pair<int,int>> current, next;
    pair<int,int> start = pair<int,int>(startX, startY);
    next.push(start);
    int turn = 0;
    i_grid[startX][startY] = turn;
    int X,Y;
    pair<int,int> cell;
    while (!next.empty()) {
        current = next;
        next = stack<pair<int,int>>();
        turn++;
        while (!current.empty()) {
            cell = current.top();
            X = cell.first;
            Y = cell.second;

            // South neighbors
            for (i = X+1; i < n; i++) {
                if (i_grid[i][Y] <= turn) {
                    if (i_grid[i][Y] != turn)
                        break;
                } else {
                    i_grid[i][Y] = turn;
                    next.push(pair<int,int>(i,Y));
                }
            }

            // North neighbors
            for (i = X-1; i >= 0 ; i--) {
                if (i_grid[i][Y] <= turn) {
                    if (i_grid[i][Y] != turn)
                        break;
                } else {
                    i_grid[i][Y] = turn;
                    next.push(pair<int,int>(i,Y));
                }
            }

            // East neighbors
            for (j = Y+1; j < n; j++) {
                if (i_grid[X][j] <= turn) {
                    if (i_grid[X][j] != turn)
                        break;
                } else {
                    i_grid[X][j] = turn;
                    next.push(pair<int,int>(X,j));
                }
            }

            // West neighbors
            for (j = Y-1; j >= 0; j--) {
                if (i_grid[X][j] <= turn) {
                    if (i_grid[X][j] != turn)
                        break;
                } else {
                    i_grid[X][j] = turn;
                    next.push(pair<int,int>(X,j));
                }
            }




            current.pop();

        }
    }


    return i_grid[goalX][goalY];
}
