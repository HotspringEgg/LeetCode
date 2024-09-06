/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
    vector<vector<int>> levelOrder(Node *root)
    {
        queue<Node *> que;
        vector<vector<int>> result;

        int size = 0;
        Node *cur = nullptr;

        if (root != NULL)
        {
            que.push(root);
        }

        while (!que.empty())
        {
            size = que.size();
            vector<int> vec;
            while (size--)
            {
                cur = que.front();
                que.pop();
                vec.push_back(cur->val);
                for (auto it = cur->children.begin(); it != cur->children.end(); it++)
                {
                    if (*it != nullptr)
                    {
                        que.push(*it);
                    }
                }
                
            }
            result.push_back(vec);
            /* code */
        }
        return result;
    }
};
// @lc code=end
