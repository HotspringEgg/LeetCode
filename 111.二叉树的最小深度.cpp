/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int getDepth(TreeNode *node)
    {
        if (node == NULL)
            return 0;

        int leftDepth = getDepth(node->left);   // 左
        int rightDepth = getDepth(node->right); // 右
                                                // 中
        // 当一个左子树为空，右不为空，这时并不是最低点
        if (node->left == NULL && node->right != NULL)
        {
            return 1 + rightDepth;
        }
        // 当一个右子树为空，左不为空，这时并不是最低点
        if (node->left != NULL && node->right == NULL)
        {
            return 1 + leftDepth;
        }
        // if (node->left == NULL && node->right == NULL)
        // {
        //     return 1 + min(leftDepth, rightDepth);
        // }
        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }

    int minDepth(TreeNode *root)
    {
        return getDepth(root);
    }
};
// @lc code=end
// int minDepth(TreeNode *root)
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
//         // vector<int> vec;
//         depth++;
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
//             if (!cur->left && !cur->right)
//             {
//                 return depth;
//             }
//         }
//         // result.push_back(vec);
//         /* code */
//     }
//     // return result;
//     return depth;
// }