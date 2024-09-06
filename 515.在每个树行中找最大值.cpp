/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<int> result;

        int size = 0;
        TreeNode *cur = nullptr;

        if (root != NULL)
        {
            que.push(root);
        }

        while (!que.empty())
        {
            size = que.size();
            vector<int> vec;
            while (size--)
            {
                cur = que.front();
                que.pop();
                vec.push_back(cur->val);
                if (cur->left)
                {
                    que.push(cur->left);
                }
                if (cur->right)
                {
                    que.push(cur->right);
                }
            }
            int max = *max_element(vec.begin(), vec.end());
            result.push_back(max);
        }
        return result;
    }
};
// @lc code=end
