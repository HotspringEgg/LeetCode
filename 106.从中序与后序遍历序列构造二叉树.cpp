/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder)
    {
        // 第一步判断是否为空
        if (inorder.size() == 0 || postorder.size() == 0)
        {
            return nullptr;
        }
        // 第二步构建子树根节点
        TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
        if (postorder.size() == 1)
        {
            return root;
        }

        // 第三步分解中序遍历数组
        int index = 0;
        for (index = 0; index < inorder.size(); index++)
        {
            if (inorder[index] == root->val)
            {
                break;
            }
        }

        vector<int> leftinorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightinorder(inorder.begin() + index + 1, inorder.end());
        postorder.resize(postorder.size() - 1);

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftinorder.size());
        vector<int> rightPostorder(postorder.begin() + leftinorder.size(), postorder.end());

        root->left = traversal(leftinorder, leftPostorder);
        root->right = traversal(rightinorder, rightPostorder);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
        {
            return nullptr;
        }

        return traversal(inorder, postorder);
    }
};
// @lc code=end
