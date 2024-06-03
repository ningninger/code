#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector< vector<int> >& triangle) {
        int h = triangle.size();
        int l = triangle[h-1].size();
        int INF = 0x3f3f3f3f;

        vector< vector<int> > f(h, vector<int>(l, 0));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < h; i++) {
            f[i][0] = f[i-1][0] + triangle[i][0];
        }

        for (int i = 1; i < h; i++) {
            for (int j  = 1; j < triangle[i].size(); j++) {
                f[i][j] = min(f[i-1][j-1], (j < triangle[i-1].size() ? f[i-1][j] : INF)) + triangle[i][j];
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                cout << f[i][j] << " ";
            }
            cout << endl;
        }

        int ans = INF;
        for (int i = 0; i < l; i++) {
            ans = min(ans, f[h-1][i]);
        }

        return ans;
    }
};
// @lc code=end

