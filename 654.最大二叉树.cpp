/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }

        int max = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                index = i;
            }
        }

        TreeNode *root = new TreeNode(max);

        vector<int> leftnums(nums.begin(), nums.begin() + index);
        vector<int> rightnums(nums.begin() + index + 1, nums.end());
        // nums.erase(index);

        root->left = constructMaximumBinaryTree(leftnums);
        root->right = constructMaximumBinaryTree(rightnums);
        return root;
    }
};
// @lc code=end
