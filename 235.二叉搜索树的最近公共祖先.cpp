/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    int target1 = 0;
    int target2 = 0;

    TreeNode *find(TreeNode *cur)
    {
        if (cur->val <= target1 && cur->val >= target2)
        {
            return cur;
        }
        else if (cur->val > target1)
        {
            return find(cur->left);
        }
        else if (cur->val < target2)
        {
            return find(cur->right);
        }
        return nullptr;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        target1 = max(p->val, q->val);
        target2 = min(p->val, q->val);
        return find(root);
    }
};
// @lc code=end
