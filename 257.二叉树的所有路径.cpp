/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void traversal(TreeNode *cur, vector<int> &path, vector<string> &result)
    {
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr)
        {
            string spath = "";
            for (int i = 0; i < path.size() - 1; i++)
            {
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size() - 1]);
            result.push_back(spath);
            return;
        }

        if (cur->left)
        {
            traversal(cur->left, path, result);
            path.pop_back();
        }

        if (cur->right)
        {
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> path;
        vector<string> result;
        if (root == nullptr)
        {
            return result;
        }

        traversal(root, path, result);
        return result;
    }
};
// @lc code=end
