// #include <algorithm>
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
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
            // 在 while (size--) 循环中，size 每次循环开始时都会先执行减1操作，然后再进入循环体
            while (size)
            {
                cur = que.front();
                que.pop();
                if (cur->left)
                {
                    que.push(cur->left);
                }

                if (cur->right)
                {
                    que.push(cur->right);
                }

                if (size == 1)
                {
                    result.push_back(cur->val);
                }
                size--;
            }
        }
        return result;
    }
};
// @lc code=end

