/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int getheight(TreeNode *cur)
    {
        //记得加终止条件
        if (cur == nullptr)
        {
            return 0;
        }

        TreeNode *left = cur->left;
        TreeNode *right = cur->right;
        int leftheight = getheight(left);
        int rightheight = getheight(right);
        if (leftheight == -1 || rightheight == -1)
        {
            return -1;
        }

        if (abs(leftheight - rightheight) > 1)
        {
            return -1;
        }

        return 1 + max(leftheight, rightheight);
    }

    bool isBalanced(TreeNode *root)
    {
        return getheight(root) == -1 ? false : true;
    }
};
// @lc code=end
