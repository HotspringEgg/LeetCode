#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> Sum(n + 1, 0);
        Sum[0] = 1;
        Sum[1] = 1;
        // if (n >= 2)
        // {
        // Sum[2] = 2;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                Sum[i] += Sum[j] * Sum[i - j - 1];
            }
        }
        /* code */
        // }
        return Sum[n];
    }
};
// @lc code=end
