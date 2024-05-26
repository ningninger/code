#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

// @lc code=start

class Solution
{

public:
    int findCheapestPrice(int n, vector< vector<int> > &flights, int src, int dst, int k) {
        // vector< vector<int> > graph(n, vector<int>(n, INT_MAX));
        // for (auto& it: flights) {
        //     graph[it[0]][it[1]] = it[2];
        // }

        vector< vector<int> > dp(k+2, vector<int>(n, INT_MAX/2));
        dp[0][src] = 0;
        for (int i = 1; i <= k+1; i++) {
            for (auto& it : flights) {
                int from = it[0], to = it[1], price = it[2];
                dp[i][to] = min(dp[i][to], dp[i-1][from] + price);
            }
        }


        int ans = INT_MAX/2;
        for (int i = 1; i <= k + 1; i++) {
            ans = min(ans, dp[i][dst]);
        }

        return ans == INT_MAX/2 ? -1 : ans;

    }
};  


  // class Solution {
    // struct flight {
    //     int index;
    //     int cost;
    //     int hop;

    //     flight(int a, int b, int c):index(a), cost(b), hop(c){};
    //     friend bool operator<(const flight &a, const flight &b)
    //     {
    //         return a.cost > b.cost;
    //     }
    // };

    // public:
    //     int findCheapestPrice(int n, vector< vector<int> >& flights, int src, int dst, int k) {
    //         vector< vector<int> > graph(n, vector<int>(n, INT_MAX));
    //         for (auto& it: flights) {
    //             graph[it[0]][it[1]] = it[2];
    //         }

    //         priority_queue<flight> q;
    //         q.push(flight(src, 0, 0));
    //         while(!q.empty()) {
    //             flight it = q.top();
    //             q.pop();
    //             if (it.hop > k + 1) {
    //                 continue;
    //             }

    //             if(it.index == dst) {
    //                 return it.cost;
    //             }

    //             for (int i = 0; i < n; i++) {
    //                 if (graph[it.index][i] != INT_MAX) {
    //                     q.push(flight(i, it.cost + graph[it.index][i], it.hop+1));
    //                 }
    //             }
    //         }

    //         return -1;

    //     }
    // };
    // @lc code=end
