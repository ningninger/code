#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <climits>
#include <cstring>

using namespace std;


/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector<int> > f(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            f[i][0] = 1;
        }

        for (int i = 0; i < n; i++) {
            f[0][i] = 1;
        }


        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }

        return f[m-1][n-1];

    }
};
// @lc code=end

