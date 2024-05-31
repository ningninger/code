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
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = (int)word1.size();
        int len2 = (int)word2.size();
        vector< vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= len2; i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);

                //注意这里需要使用i-1和j-1，因为我们的遍历是从1开始的
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
                else {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
                }
            }
        }

        return dp[len1][len2];

    }
};
// @lc code=end

