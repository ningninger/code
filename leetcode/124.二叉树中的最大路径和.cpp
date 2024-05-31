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
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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

//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };


class Solution {
public:

    int maxPath(TreeNode* node, int& ans) {
        if (node == NULL) {
            return 0;
        }

        int left = max(maxPath(node->left, ans), 0);
        int right = max(maxPath(node->right, ans), 0);

        int sum = left + right + node->val;

        cout << sum << endl;

        ans = max(ans, sum);


        return max(left, right) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        
        maxPath(root, ans);
        
        return ans;
    }
};
// @lc code=end

