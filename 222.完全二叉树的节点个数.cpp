/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int getNumber(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftDepth = 0;
        int rightDepth = 0;
        while (left)
        {
            left = left->left;
            leftDepth++;
        }

        while (right)
        {
            right = right->right;
            rightDepth++;
        }

        if (rightDepth == leftDepth)
        {
            return (2 << (leftDepth)) - 1;
        }
        //此时left和right以及被更改，所以要传入原值
        return getNumber(root->left) + getNumber(root->right) + 1;
    }

    int countNodes(TreeNode *root)
    {
        return getNumber(root);
    }
};
// @lc code=end
