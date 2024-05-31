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
#include <climits>
#include <cstring>

using namespace std;


/*
 * @lc app=leetcode.cn id=3082 lang=cpp
 *
 * [3082] 求出所有子序列的能量和
 */

// @lc code=start
class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        //能量表示等于k的子数列的数目

        //比方说(1,2,3)的子序列(2, 3)等于3的的子序列为1，所以该(2,3)的能量为1

        int n = nums.size();
        vector< vector<int> > f(n + 1, vector<int>(n + 1, 0));

        int ans = 0;
        

        
    }
};
// @lc code=end

