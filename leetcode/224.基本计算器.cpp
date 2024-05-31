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
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:

    string trim(const string& s) {
        string str = "";
        for (char ch: s) {
            if (ch != ' ') {
                str += ch;
            }
        }
        return str;
    }

    bool isOperator(char ch) {
        return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');
    }

    int getPriority(char ch) {
         if (ch == '+' || ch == '-') return 1;
         else if (ch == '*' || ch == '/') return 2;
         return 0;
    }

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

int calculate(string s) {
        string str = trim(s);
        string exp = "";
        vector<string> RPN;
        stack<char> operators;
        bool isminus = false;
        int num = -1;

        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if (isdigit(c)) {
                num = num == -1 ? c - '0' :  num*10 + (c - '0');       
                isminus = true;  
            } else {
                if (num != -1) {
                    exp += to_string(num);
                    exp += " ";
                    RPN.push_back(to_string(num));
                    num = -1;
                }
                if (c == '(') {
                    operators.push(c);
                    isminus = false;
                } else if (c == ')') {
                    while(!operators.empty() && operators.top() != '(') {
                        exp += operators.top();
                        exp += " ";
                        RPN.push_back(string(1, operators.top()));
                        operators.pop(); 
                    }

                    if (!operators.empty()) {
                        operators.pop();
                    }
                    isminus = true;
                } else if (isOperator(c)) {
                    if (c == '-' && !isminus) {
                        exp += to_string(0);
                        exp += " ";
                        RPN.push_back(to_string(0));
                    }
                    while (!operators.empty() && getPriority(c) <= getPriority(operators.top())) {
                        exp += operators.top();
                        exp += " ";
                        RPN.push_back(string(1, operators.top()));
                        operators.pop();
                    } 
                    operators.push(c);
                }
            }
        }

        if (num != -1) {
            exp += to_string(num);
            exp += " ";
            RPN.push_back(to_string(num));
            num = -1;
        }
        
        while(!operators.empty()) {
            exp += operators.top();
            exp += " ";
            RPN.push_back(string(1, operators.top()));
            operators.pop();
        }
        cout << exp << endl;
        int ans = evalRPN(RPN);
        return ans;
    }
};
// @lc code=end

