/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int maxCount = 0; // 最大频率
    int count = 0;    // 统计频率
    TreeNode *pre = nullptr;
    vector<int> result;

    void Count(TreeNode *cur)
    {
        if (!cur)
        {
            return;
        }

        Count(cur->left);

        //第一个节点
        if (!pre)
        {
            count = 1;
        }
        else if (cur->val == pre->val)
        {
            count++;
        }
        else
        {
            count = 1;
        }

        if (count == maxCount)
        {
            result.push_back(cur->val);
        }

        if (count > maxCount)
        {
            maxCount = count;
            result.clear();
            result.push_back(cur->val);
        }

        pre = cur;
        Count(cur->right);
    }

    vector<int> findMode(TreeNode *root)
    {
        count = 0;
        maxCount = 0;
        pre = nullptr;
        result.clear();

        Count(root);
        return result;
    }
};
// @lc code=end
