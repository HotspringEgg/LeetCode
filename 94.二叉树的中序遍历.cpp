#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;

        if (root != nullptr)
        {
            st.push(root);
        }

        while (!st.empty())
        {
            TreeNode *cur = st.top();
            if (cur)
            {
                st.pop();
                if (cur->right)
                {
                    st.push(cur->right);
                }
                st.push(cur);
                st.push(nullptr);
                if (cur->left)
                {
                    st.push(cur->left);
                }
            }
            else
            {
                st.pop();
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
            }
        }
        return result;
    }
};
// @lc code=end

// 9-11

// 递归
// vector<int> result;
// vector<int> inorderTraversal(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return result;
//     }

//     inorderTraversal(root->left);
//     result.push_back(root->val);
//     inorderTraversal(root->right);
//     return result;
// }

// void travelsal(TreeNode *cur, vector<int> &result)
// {
//     if (cur == nullptr)
//     {
//         return;
//     }
//     travelsal(cur->left, result);
//     result.push_back(cur->val);
//     travelsal(cur->right, result);
// }

// vector<int> inorderTraversal(TreeNode *root)
// {
//     vector<int> result;
//     // travelsal(root, result);
//     TreeNode *cur = root;
//     stack<TreeNode *> st;
//     while (cur != nullptr || !st.empty())
//     {
//         if (cur != nullptr)
//         {
//             st.push(cur);
//             cur = cur->left;
//         }
//         else
//         {
//             cur = st.top();
//             st.pop();
//             result.push_back(cur->val);
//             cur = cur->right;
//         }
//     }

//     return result;
// }