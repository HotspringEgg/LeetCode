/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
class Solution
{
public:
    void invert(TreeNode *cur)
    {
        if (cur == nullptr)
        {
            return;
        }
        
        swap(cur->left, cur->right);
        invert(cur->left);
        invert(cur->right);
    }

    TreeNode *invertTree(TreeNode *root)
    {
        invert(root);
        return root;
    }
};
// @lc code=end
