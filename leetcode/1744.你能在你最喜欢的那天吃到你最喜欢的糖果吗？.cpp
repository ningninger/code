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
 * @lc app=leetcode.cn id=1744 lang=cpp
 *
 * [1744] 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 */

// @lc code=start
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<bool> answer(queries.size(), false);
        vector<long long> sums(candiesCount.size(), 0);
        long long sum = 0;
        for (int i = 0; i < candiesCount.size(); i++) {
            sum += candiesCount[i];
            sums[i] = sum;
        }

        for (int i = 0; i < queries.size(); i++) {
            auto& query = queries[i];
            long long type = query[0], day = query[1], cap = query[2];
            
            if (type == 0 && day < sums[0]) {
                answer[i] = true;
                continue;
            }

            if (day < sums[type] && cap * (day + 1) > sums[type-1]) {
                answer[i] = true;
                continue;
            }
        }

        return answer;
    }
};
// @lc code=end

