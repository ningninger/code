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
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        auto matches = [&](int i, int j) {
            if (i <= 1 || j <= 1) {
                return false;
            }
            if (p [j] == '.') {
                return true;
            } 
            return s[i] == p[j];
        };

        int m = s.size();
        int n = p.size();

        vector< vector<int> > f(m + 1, vector<int>(n + 1) );
        f[0][0] = 1;

        //f[i][j] 表示s[0, i-1]和p[0, j-1]是否能匹配上，能匹配就true
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    //如果一个发现了*，会将这个
                    f[i][j] = f[i][j] || f[i][j-1];
                    if (matches(i-1, j-2)) {
                        f[i][j] = f[i][j] || f[i-1][j];
                    }
                } else {
                    if (matches(i-1, j-1)) {
                        f[i][j] = f[i][j] || f[i-1][j-1];
                    }
                }
            }
        }

        return f[m][n];


    }
};
// @lc code=end

