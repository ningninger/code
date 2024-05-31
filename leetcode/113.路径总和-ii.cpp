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
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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

    void dfs(vector< vector<int> >&graph, TreeNode* node, vector<int>& cur_nodes, int sum, int cur) {
        if (node == NULL) {return;}

        cur += node->val;
        cur_nodes.push_back(node->val);

        if (cur == sum && node->left == NULL && node->right == NULL) {
            vector<int> temp = cur_nodes;
            graph.push_back(temp);
        } else {
            dfs(graph, node->left, cur_nodes, sum, cur);
            dfs(graph, node->right, cur_nodes, sum, cur);
        }
        cur_nodes.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector< vector<int> > paths;
        vector<int> cur_nodes;
        dfs(paths, root, cur_nodes, targetSum, 0);
        return paths;

    }
};
// @lc code=end

