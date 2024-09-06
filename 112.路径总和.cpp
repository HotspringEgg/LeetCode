/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    int target;
    bool findpath(TreeNode *cur, int target)
    {
        if (cur->left == nullptr && cur->right == nullptr)
        {
            if (target == 0)
            {
                return true;
            }
            return false;
        }

        if (cur->left)
        {
            target = target - cur->left->val;
            if (findpath(cur->left, target))
            {
                return true;
            }
            // return findpath(cur->left, target);
            target = target + cur->left->val;
        }
        if (cur->right)
        {
            target = target - cur->right->val;
            if (findpath(cur->right, target))
            {
                return true;
            }
            // return findpath(cur->left, target);
            target = target + cur->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;

        this->target = targetSum;
        return findpath(root, targetSum - root->val);
    }
};
// @lc code=end
