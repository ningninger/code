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
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        //O(nlogn)

        // vector<int> temp;
        // for (int i = 0; i < nums.size(); i++) {
        //     auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
        //     if (it != temp.end()) {
        //         *it = nums[i];
        //     } else {
        //         temp.push_back(nums[i]);
        //     }
        // }
        // return temp.size();


        int len = nums.size();   
        vector<int> dp(len, 0);
        int ans = 0;
        //dp[i]表示以nums[i]结尾的最长的递增子序列的话
        for (int i = 0; i < len; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

