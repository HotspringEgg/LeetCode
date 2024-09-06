/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int getDepth(TreeNode *cur)
    {
        if (cur == NULL)
            return 0;
        int leftdepth = getDepth(cur->left);       // 左
        int rightdepth = getDepth(cur->right);     // 右
        int depth = 1 + max(leftdepth, rightdepth); // 中
        return depth;
    }

    int maxDepth(TreeNode *root)
    {
        int depth = 0;
        return getDepth(root);
    }
};
// @lc code=end

// int maxDepth(TreeNode *root)
// {
//     queue<TreeNode *> que;
//     // vector<vector<int>> result;

//     int size = 0;
//     int depth = 0;
//     TreeNode *cur = nullptr;

//     if (root != NULL)
//     {
//         que.push(root);
//     }

//     while (!que.empty())
//     {
//         size = que.size();
//         depth++;
//         // vector<int> vec;
//         while (size--)
//         {
//             cur = que.front();
//             que.pop();
//             // vec.push_back(cur->val);
//             if (cur->left)
//             {
//                 que.push(cur->left);
//             }
//             if (cur->right)
//             {
//                 que.push(cur->right);
//             }
//         }
//         // result.push_back(vec);
//         /* code */
//     }
//     // return result;
//     return depth;
// }
