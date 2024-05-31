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
 * @lc app=leetcode.cn id=741 lang=cpp
 *
 * [741] 摘樱桃
 */

// @lc code=start
class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        int INF = ~0x3f3f3f3f;


        int len = (int)grid.size();
        //两个人同时走，都从左往下
        int dp[53][53][53][53];
        dp[1][1][1][1] = grid[0][0];

        for (int k = 1; k <= len*2 - 2; k++) {
            for (int i = max(1, k+2-len); i <= min(len, k+1); i++) {
                int j = k - i + 2;
                for (int m = max(1, k+2-len); m <= min(len, k+1); m++) {
                    int n = k - m + 2;
                    dp[i][j][m][n] = INF;
                    if (grid[i-1][j-1] == -1 || grid[m-1][n-1] == -1) {
                            dp[i][j][m][n] = INF;
                            continue;
                        }
                    // A向下， B向下
                    if (j > 1 && n > 1)
                    dp[i][j][m][n] = max(dp[i][j][m][n], dp[i][j-1][m][n-1] + grid[i-1][j-1] + (i != m ? grid[m-1][n-1]:0));

                    // A向下， B向右
                    if (j > 1 && m > 1)
                    dp[i][j][m][n] = max(dp[i][j][m][n], dp[i][j-1][m-1][n] + grid[i-1][j-1] + (i != m ? grid[m-1][n-1]:0));
                        
                    // A向右， B向下
                    if (i > 1 && n > 1)
                    dp[i][j][m][n] = max(dp[i][j][m][n], dp[i-1][j][m][n-1] + grid[i-1][j-1] + (i != m ? grid[m-1][n-1]:0));

                    // A向右， B向右
                    if (i > 1 && m > 1)
                    dp[i][j][m][n] = max(dp[i][j][m][n], dp[i-1][j][m-1][n] + grid[i-1][j-1] + (i != m ? grid[m-1][n-1]:0));
                
                     // Print dp[i][j][m][n]
                     //   cout << "dp[" << i << "][" << j << "][" << m << "][" << n << "] = " << dp[i][j][m][n] << endl;
                }
            }
        }
        


        return max(dp[len][len][len][len], 0);

    }
};
// @lc code=end

