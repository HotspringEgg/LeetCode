/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int result = INT_MAX;
    TreeNode *pre = nullptr;
    void getDifference(TreeNode *cur)
    {
        if (!cur)
        {
            return;
        }

        getDifference(cur->left);

        if (pre)
        {
            result = min(result, cur->val - pre->val);
        }

        pre = cur;
        getDifference(cur->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        getDifference(root);
        return result;
    }
};
// @lc code=end
