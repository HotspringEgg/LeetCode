/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> que;
        // vector<vector<int>> result;

        int size = 0;
        Node *cur = nullptr;

        if (root != NULL)
        {
            que.push(root);
        }

        while (!que.empty())
        {
            size = que.size();
            for (int i = 0; i < size; i++)
            {
                cur = que.front();
                que.pop();
                if (i == size - 1)
                {
                    cur->next = nullptr;
                }
                else
                {
                    cur->next = que.front();
                }

                if (cur->left)
                {
                    que.push(cur->left);
                }
                if (cur->right)
                {
                    que.push(cur->right);
                }
            }
            /* code */
        }
        return root;
    }
};
// @lc code=end
