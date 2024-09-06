/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode *root)
    {

        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 0;
        }

        int leftsum = sumOfLeftLeaves(root->left);  //左
        int rightsum = sumOfLeftLeaves(root->right);//右

        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        {
            leftsum = root->left->val;
        }                                           //中

        int sum = leftsum + rightsum;

        return sum;
    }
};
// @lc code=end
