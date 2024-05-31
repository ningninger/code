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
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        int first = 1;
        int second = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            first--;

            if (it->left != NULL) {
                q.push(it->left);
                second++;
            }

            if (it->right != NULL) {
                q.push(it->right);
                second++;
            }

            if (first == 0) {
                ans.push_back(it->val);
                first = second;
                second = 0;
            }
        }

        return ans;
        
    }
};
// @lc code=end

