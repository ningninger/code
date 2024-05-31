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
#include <cstring>

using namespace std;


/*
 * @lc app=leetcode.cn id=1463 lang=cpp
 *
 * [1463] 摘樱桃 II
 */

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();

        int f[rows][cols][rows][cols];

        //initilal error: memset(f, 0, sizeof(f));
        memset(f, ~0x3f3f3f3f, sizeof(f));

        f[0][0][0][cols-1] = grid[0][0] + grid[0][cols-1];
        
        

        for (int i = 1; i < rows; i++) {
            for (int m = 0; m < cols; m++) {
                for (int n = 0; n < cols; n++) {
                    for (int pm = max(m-1, 0); pm <= min(m+1, cols-1); pm++) {
                        for (int pn = max(n-1, 0); pn <= min(n+1, cols-1); pn++) {
                            f[i][m][i][n] = max(f[i][m][i][n], f[i-1][pm][i-1][pn] + grid[i][m] + (m != n ? grid[i][n] : 0));
                        }
                    }
                }
            }
        }


        int ans = 0;
        for (int m = 0; m < cols; m++) {
            for (int n = 0; n < cols; n++) {
                ans = max(ans, f[rows-1][m][rows-1][n]);
                cout << f[rows-1][m][rows-1][n] << " ";
            }
        }

        return ans;
    }
};
// @lc code=end

