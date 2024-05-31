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
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' && isdigit(tokens[i][1]))) {
                stk.push(stoi(tokens[i]));
            } else {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                int c = 0;
                switch(tokens[i][0]) {
                    case '+':
                        c = b + a;
                        break;
                    case '-':
                        c = b - a;
                        break;
                    case '*':
                        c = b * a;
                        break;
                    case '/':
                        c = b / a;
                        break;
                    default:
                        cout << "op error" << endl;
                        exit(EXIT_FAILURE);
                }
                cout << c << endl;
                stk.push(c);
            }
        }
        return stk.top();
    }
};
// @lc code=end

