/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *traversal(vector<int> &preorder, vector<int> &inorder)
    {
        // 第一步判断是否为空
        if (preorder.size() == 0 || inorder.size() == 0)
        {
            return nullptr;
        }
        // 第二步构建子树根节点
        TreeNode *root = new TreeNode(preorder[0]);
        if (preorder.size() == 1)
        {
            return root;
        }

        // 第三步确定中序遍历中根节点的位置
        int index = 0;
        for (index = 0; index < inorder.size(); index++)
        {
            if (inorder[index] == root->val)
            {
                break;
            }
        }
        //根据index分解中序遍历数组
        vector<int> leftinorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightinorder(inorder.begin() + index + 1, inorder.end());
        preorder.erase(preorder.begin());

        vector<int> leftpreorder(preorder.begin(), preorder.begin() + leftinorder.size());
        vector<int> rightpreorder(preorder.begin() + leftinorder.size(), preorder.end());

        root->left = traversal(leftpreorder, leftinorder);
        root->right = traversal(rightpreorder, rightinorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
        {
            return nullptr;
        }

        return traversal(preorder, inorder);
    }
};
// @lc code=end

