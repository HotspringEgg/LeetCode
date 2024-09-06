/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
        {
            return root;
        }
        else if (root->val == key)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                root = nullptr;
                return root;
            }
            if (root->left == nullptr && root->right != nullptr)
            {
                auto retNode = root->right;
                ///! 内存释放
                delete root;
                return retNode;
            }
            if (root->left != nullptr && root->right == nullptr)
            {
                auto retNode = root->left;
                ///! 内存释放
                delete root;
                return retNode;
            }
            if (root->left != nullptr && root->right != nullptr)
            {
                TreeNode *cur = root->right;
                while (cur->left)
                {
                    cur = cur->left;
                }
                cur->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
                TreeNode *tmp = root;   // 把root节点保存一下，下面来删除
                root = root->right;     // 返回旧root的右孩子作为新root
                delete tmp;             // 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
                return root;
            }
        }
        if (root->val > key)
        {
        root->left = deleteNode(root->left, key);
        }
        if (root->val < key)
        {
        root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
// @lc code=end
