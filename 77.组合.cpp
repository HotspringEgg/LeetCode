#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int k, int n, int startIndex)
    {
        // 8-25
        if (path.size() == k)
        {
            result.push_back(path);
        }
        // 此处可优化为i <= n - (k - path.size()) + 1
        // k - path.size()是尚且缺少的元素数
        // 即i至多从n - (k - path.size()) + 1开始
        // 比如从1-4中取4个数
        // 至多只能从1开始
        for (int i = startIndex; i <= n; i++)
        {
            path.push_back(i);
            backtracking(k, n, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backtracking(k, n, 1);
        return result;
    }
};
// @lc code=end

// void backtracking(int n, int k, int startIndex)
// {
//     if (path.size() == k)
//     {
//         result.push_back(path);
//         return;
//     }
//     else if (path.size() < k)
//     {
//         for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)
//         {
//             path.push_back(i);
//             backtracking(n, k, i + 1);
//             path.pop_back();
//         }
//     }
// }