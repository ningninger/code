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
 * @lc app=leetcode.cn id=2588 lang=cpp
 *
 * [2588] 统计美丽子数组数目
 */

// @lc code=start
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> dic;

        vector<long long> sums(n+1, 0);
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum ^= nums[i];
            sums[i+1] = sum;
        }

        long long ans = 0;
        //问题修改成sums中有多少对相同的元素
        for (long long sum: sums) {
            ans += dic[sum];
            dic[sum]++;
        }

        return ans;
    }
};
// @lc code=end

