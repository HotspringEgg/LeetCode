#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=3142 lang=cpp
 *
 * [3142] 判断矩阵是否满足条件
 */

// @lc code=start
class Solution
{
public:
    bool satisfiesConditions(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (i + 1 < grid.size() && grid[i][j] != grid[i + 1][j])
                {
                    return false;
                }
                if (j + 1 < grid[0].size() && grid[i][j] == grid[i][j + 1])
                {
                    return false;
                }
            }
            
        }
        return true;
    }
};
// @lc code=end
