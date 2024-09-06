/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        if (nums.size() > 1)
        {
            vector<int> leftArray(nums.begin(), nums.begin() + mid);
            if (leftArray.size() > 0)
            {
                root->left = sortedArrayToBST(leftArray);
            }

            vector<int> rightArray(nums.begin() + mid + 1, nums.end());
            if (rightArray.size() > 0)
            {
                root->right = sortedArrayToBST(rightArray);
            }
        }
        return root;
    }
};
// @lc code=end
