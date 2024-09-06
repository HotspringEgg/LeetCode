#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    vector<int> robTree(TreeNode *cur)
    {
        if (cur == nullptr)
        {
            return {0, 0};
        }
        
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);

        vector<int> dp(2);
        // 不偷该节点, 左右节点可偷可不偷，取较大情况
        dp[0] = max(left[0], left[1]) + max(right[0], right[1]);
        // 偷该节点
        dp[1] = cur->val + left[0] + right[0];
        return dp;
    }

    int rob(TreeNode *root)
    {
        vector<int> dp(2);
        dp = robTree(root);
        return max(dp[0], dp[1]);
    }
};
// @lc code=end
