#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector< vector<int> >& times, int n, int k) {
        vector< vector<int> > graph(n + 1, vector<int>(n + 1, INT_MAX));
        for (auto& it : times) {
            graph[it[0]][it[1]] = it[2];
        }


        vector<int> dist(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);
        dist[k] = 0;


        for (int i = 0; i < n; i++) {
            int u = -1;
            int minDist = INT_MAX;
            for (int j = 1; j <= n; j++)
            {
                if (!visited[j] && dist[j] < minDist) {
                    u = j;
                    minDist = dist[j];
                }
            }
            if (u == -1) {
                return -1;
            }
            visited[u] = true;
            for (int v = 1; v <= n; v++) {
                if (!visited[v] && graph[u][v] != INT_MAX) {
                    dist[v] = min(dist[v], dist[u] + graph[u][v]);
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
            {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
// @lc code=end

