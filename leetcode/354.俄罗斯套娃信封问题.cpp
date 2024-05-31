#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;


/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:

    void dfs(map<int, vector<int> >& graph, vector<bool>& visited, int cur, int height, int& ans) {
        ans = max(ans, height);

        visited[cur] = true;
        for (int to: graph[cur]) {
            if (!visited[to]) {
                dfs(graph, visited, to, height + 1, ans);
            }
        }

        visited[cur] = false;
    }

    int solverByGraph(vector< vector<int> >& envelopes) {
        map<int, vector<int> > graph;
        for (int i = 0; i < envelopes.size(); i++) {
            for (int j = 0; j < envelopes.size(); j++) {
                if (i != j) {
                    auto a = envelopes[i];
                    auto b = envelopes[j];
                    if (a[0] > b[0] && a[1] > b[1]) {
                        //b -> a
                        graph[i].push_back(j);
                    }
                }
            }
            graph[envelopes.size()].push_back(i);
        }


        // cout << "Graph:" << endl;
        // for (auto& entry : graph) {
        //     if (entry.first != envelopes.size()) {
        //         cout << entry.first <<": [" <<envelopes[entry.first][0] << ","  << envelopes[entry.first][1]<< "]" << ": ";
        //         for (auto& node : entry.second) {
        //             cout << "[" <<envelopes[node][0] << ","  << envelopes[node][1]<< "]" << " ";
        //         }
        
        //         cout << endl;
        //     }
            
        // }

        vector<bool> visited(envelopes.size(), false);

        int ans = 0;
        dfs(graph, visited, (int)envelopes.size(), 0, ans);

        return ans;
    }


    int maxEnvelopes(vector< vector<int> >& envelopes) {
        //第一种做法：使用图来解决，也就是说，对于点a来说，只有a 绝对大于b的时候才会存在a -> b的边
        return solverByGraph(envelopes);
    }
};
// @lc code=end

