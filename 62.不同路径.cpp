#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> map(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            map[i][0] = 1;
        }

        for (int j = 0; j < n; j++)
        {
            map[0][j] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
        }
        return map[m - 1][n - 1];
    }
};
// @lc code=end
