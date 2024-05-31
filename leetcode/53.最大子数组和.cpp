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
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int m = INT_MIN;
        vector<int> dp(len+1, 0);
        for (int i = 1; i <= len; i++) {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            m = max(m, dp[i]);
        }
        return m;
    }
};
// @lc code=end

