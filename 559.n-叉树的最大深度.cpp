/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    int getDepth(Node *cur)
    {
        if (cur == NULL)
        {
            return 0;
        }
        int maxDepth = 0;
        for (int i = 0; i < cur->children.size(); i++)
        {
            int childDepth = getDepth(cur->children[i]);
            maxDepth = maxDepth > childDepth ? maxDepth : childDepth;
            
            // maxDepth = maxDepth > getDepth(cur->children[i]) ? maxDepth : getDepth(cur->children[i]);
        }
        int depth = maxDepth + 1;
        return depth;
    }

    int maxDepth(Node *root)
    {
        int depth = 0;
        return getDepth(root);
    }
};
// @lc code=end
