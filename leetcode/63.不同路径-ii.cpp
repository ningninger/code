#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int INF = ~0x3f3f3f3f;
        vector< vector<int> > f(m, vector<int>(n, 0));

        f[0][0] = obstacleGrid[0][0] ? INF : 1;
        for (int i = 1; i < m; i++) {
            f[i][0] =  obstacleGrid[i][0] ? INF : f[i-1][0];
        }

        for (int i = 1; i < n; i++) {
            f[0][i] = obstacleGrid[0][i] ? INF : f[0][i-1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    f[i][j] = max(max(f[i - 1][j] + f[i][j - 1], f[i-1][j]), f[i][j-1]);
                } else {
                    f[i][j] = INF;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << f[i][j] << " ";
            }
            cout << endl;
        }



        return max(f[m-1][n-1], 0);
    }
};
// @lc code=end

