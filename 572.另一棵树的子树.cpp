/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q != nullptr)
        {
            return false;
        }
        else if (p != nullptr && q == nullptr)
        {
            return false;
        }
        else if (p == nullptr && q == nullptr)
        {
            return true;
        }
        // 排除了空节点，再排除数值不相同的情况
        else if (p->val != q->val)
        {
            return false;
        }
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return (left && right);
    }

    void traversal(TreeNode *root, vector<TreeNode *> &vec)
    {
        if (root == nullptr)
        {
            return;
        }

        vec.push_back(root);
        traversal(root->left, vec);
        traversal(root->right, vec);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        vector<TreeNode *> vec;
        traversal(root, vec);
        for (int i = 0; i < vec.size(); i++)
        {
            int result = isSameTree(vec[i], subRoot);
            if (result)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
