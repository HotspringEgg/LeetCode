#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    // void travelsal(TreeNode *cur, vector<int> &result)
    // {
    //     if (cur == nullptr)
    //     {
    //         return;
    //     }
    //     travelsal(cur->left, result);
    //     travelsal(cur->right, result);
    //     result.push_back(cur->val);
    // }

    vector<int> postorderTraversal(TreeNode *root)
    {
        // vector<int> result;
        // travelsal(root, result);
        // return result;

        stack<TreeNode *> st;
        vector<int> result;
        // if (root == nullptr)
        // {
        //     return result;
        // }

        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            if (node)
            {
                result.push_back(node->val);
                // if (node->left != nullptr)
                // {
                st.push(node->left);
                // }
                // if (node->right != nullptr)
                // {
                st.push(node->right);
                // }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
