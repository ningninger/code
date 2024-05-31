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
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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

    //这里考虑是左闭右闭
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int preL, int preR, int postL, int postR) {
        //这里我们就要考虑如何判断该节点属于右子树还是左子树

        if (preL > preR || postL > postR) {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[preL]);

        if (preL == preR) {
            return node;
        }
        
        int left = preorder[preL+1];
        auto it = find(postorder.begin() + postL, postorder.begin() + postR, left);
        int leftover = distance(postorder.begin(), it); // 计算 left 在 postorder 中的索引
        int num = leftover - postL + 1; // 左子树节点数量

        node->left = construct(preorder, postorder, preL + 1, preL + num, postL, leftover);
        node->right = construct(preorder, postorder, preL + 1 + num, preR, leftover + 1, postR - 1);
         
        return node;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        //前序遍历的数组首节点必定是子树的根节点，但是不知道后面的左右子树是怎么划分的
        //后序遍历的数组尾节点必定是子树的根节点，但是也不知道后面的左右子树的划分
        return construct(preorder, postorder, 0, preorder.size()-1, 0, postorder.size()-1);
    }
};
// @lc code=end

