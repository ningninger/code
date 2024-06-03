#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector< vector<int> >& matrix) {
        int n = matrix.size();
        int INF = 0x3f3f3f3f;
        vector< vector<int> > f(n, vector<int>(n + 2, INF));
        for (int j = 1; j <= n; j++) {
            f[0][j] = matrix[0][j-1];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i-1][j+1])) + matrix[i][j-1];
            }
        }

        int ans = INF;
        for (int j = 1; j <= n; j++) {
            ans = min(ans, f[n-1][j]);
        }
        return ans;
    }
};
// @lc code=end

