#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;

        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();

            if (cur != nullptr)
            {
                result.push_back(cur->val);

                if (cur->right)
                {
                    st.push(cur->right);
                }
                if (cur->left)
                {
                    st.push(cur->left);
                }
            }
        }
        return result;
    }
};
// @lc code=end

// 9-11

// 递归
//  vector<int> result;
//  vector<int> preorderTraversal(TreeNode *root)
//  {
//      if (root == nullptr)
//      {
//          return result;
//      }

//     result.push_back(root->val);
//     preorderTraversal(root->left);
//     preorderTraversal(root->right);
//     return result;
// }

// first
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// void travelsal(TreeNode *cur, vector<int>& result)
// {
//     if (cur == nullptr)
//     {
//         return;
//     }
//     result.push_back(cur->val);
//     travelsal(cur->left, result);
//     travelsal(cur->right, result);
// }

// vector<int> preorderTraversal(TreeNode *root)
// {
//     stack<TreeNode *> st;
//     vector<int> result;
//     // if (root == nullptr)
//     // {
//     //     return result;
//     // }

//     st.push(root);
//     while (!st.empty())
//     {
//         TreeNode *node = st.top();
//         st.pop();
//         if (node)
//         {
//             result.push_back(node->val);
//             // if (node->right != nullptr)
//             // {
//             st.push(node->right);
//             // }

//             // if (node->left != nullptr)
//             // {
//             st.push(node->left);
//             // }
//         }
//     }
//     return result;
// }