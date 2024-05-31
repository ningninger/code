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
 * @lc app=leetcode.cn id=1514 lang=cpp
 *
 * [1514] 概率最大的路径
 */

// @lc code=start
class Solution {
public:
    struct node {
        int index;
        double dist;

        node(int a, double b):index(a), dist(b){};

        bool operator < (const node& other) const {
            return dist < other.dist;
        }
    };

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        double INF = 1e9 + 7;
        vector< vector< pair<int, double> > > graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            double w = succProb[i];
            graph[a].emplace_back(b, w);
            graph[b].emplace_back(a, w);
        }

        vector<double> dist(n, 0);
        dist[start_node] = 1;

        priority_queue<node> pq;
        pq.push(node(start_node, 1));
        while (!pq.empty()) {
            int cur_index = pq.top().index;
            double cur_dist = pq.top().dist;
            pq.pop();

            if (cur_index == end_node) {
                return cur_dist;
            }

            for (auto& it: graph[cur_index]) {
                int to = it.first;
                double weight = it.second;
                double distance = cur_dist * weight;

                if (distance > dist[to]) {
                    dist[to] = distance;
                    pq.push(node(to, distance));
                }

            }
        }   
        return 0;
    }

    // double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    //     double INF = 1e9 + 7;
    //     vector< vector<double> > graph(n, vector<double>(n, INF));
    //     for (int i = 0; i < edges.size(); i++) {
    //         int a = edges[i][0], b = edges[i][1];
    //         double w = succProb[i];
    //         graph[a][b] = w;
    //         graph[b][a] = w;
    //     }

    //     vector<double> dist(n, 0);
    //     vector<bool> visited(n, false);
    //     dist[start_node] = 1;

    //     for (int i = 0; i < n; i++) {
    //         int u = -1;
    //         for (int i = 0; i < n; i++) {
    //             if (!visited[i] && (u == -1 || dist[i] > dist[u])) {
    //                 u = i;
    //             }
    //         }
    //         if (u == -1) {
    //             break;
    //         }

    //         visited[u] = true;

    //         for (int i = 0; i < n; i++) {
    //             if (!visited[i] && graph[u][i] != INF) {
    //                 dist[i] = max(dist[i], dist[u] * graph[u][i]);
    //             }
    //         }
    //     }

    //     return dist[end_node];
    // }

    // double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    //     int INF = 1e9+ 7;
    //     vector<double> dist(n, 0);

    //     dist[start_node] = 1;
    //     for (int i = 0; i < n - 1; i++) {
    //         vector<double> temp = dist;
    //         for (int j = 0; j < edges.size(); j++) {
    //             double a = edges[j][0], b = edges[j][1], w = succProb[j];
    //             if (dist[a] != 0) {
    //                 temp[b] = max(temp[b], dist[a] * w);
    //             }
    //             if (dist[b] != 0) {
    //                 temp[a] = max(temp[a], dist[b] * w);
    //             }
    //         }
    //         dist = temp;
    //     }

    //     for (double i: dist) {
    //         cout << i << " ";
    //     }
    //     return dist[end_node];

    // }
};
// @lc code=end

