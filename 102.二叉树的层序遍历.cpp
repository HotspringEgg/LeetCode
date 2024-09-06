#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<vector<int>> result;

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
            result.push_back(vec);
            /* code */
        }
        return result;
    }
};
// @lc code=end
