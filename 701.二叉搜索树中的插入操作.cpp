/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    void traversal(TreeNode *root, int val)
    {
        if (val > root->val && root->right != nullptr)
        {
            traversal(root->right, val);
        }
        else if (val < root->val && root->left != nullptr)
        {
            traversal(root->left, val);
        }
        else if (val > root->val && root->right == nullptr)
        {
            root->right = new TreeNode(val);
        }
        else if (val < root->val && root->left == nullptr)
        {
            root->left = new TreeNode(val);
        }
    }

    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
        {
            root = new TreeNode(val);
        }
        traversal(root, val);
        return root;
    }
};
// @lc code=end
