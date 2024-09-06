/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> result;
    vector<int> path;

    void findpath(TreeNode *cur, int target)
    {
        if (cur->left == nullptr && cur->right == nullptr)
        {
            if (target == 0)
            {
                result.push_back(path);
            }
            return;
        }

        if (cur->left)
        {
            path.push_back(cur->left->val);
            target = target - cur->left->val;
            findpath(cur->left, target);
            // return findpath(cur->left, target);
            path.pop_back();
            target = target + cur->left->val;
        }

        if (cur->right)
        {
            path.push_back(cur->right->val);
            target = target - cur->right->val;
            findpath(cur->right, target);
            // return findpath(cur->left, target);
            path.pop_back();

            target = target + cur->right->val;
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return result;
        }

        path.push_back(root->val);
        findpath(root, targetSum - root->val);
        return result;
    }
};
// @lc code=end
