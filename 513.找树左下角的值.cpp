/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int maxDepth = -1;
    int result;
    void traversal(TreeNode *cur, int depth)
    {
        if (cur->left == nullptr && cur->right == nullptr)
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                result = cur->val;
            }
            return;
        }
        
        if (cur->left)
        {
            // 传入depth+1,函数返回值depth不变
            traversal(cur->left, depth + 1);
            //等价于
            // depth++;
            // traversal(cur->left, depth);
            // depth--;
        }
        if (cur->right)
        {
            traversal(cur->right, depth + 1);
        }
        // return;
    }

    int findBottomLeftValue(TreeNode *root)
    {
        traversal(root, 1);
        return result;
    }
};
// @lc code=end
