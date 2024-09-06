#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> map(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            map[i][0] = 1;
            if (obstacleGrid[i][0] == 1)
            {
                map[i][0] = 0;
                break;
            }
        }

        for (int j = 0; j < n; j++)
        {
            map[0][j] = 1;
            if (obstacleGrid[0][j] == 1)
            {
                map[0][j] = 0;
                break;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                map[i][j] = map[i - 1][j] + map[i][j - 1];
                if (obstacleGrid[i][j] == 1)
                {
                    map[i][j] = 0;
                }
            }
        }
        return map[m - 1][n - 1];
    }
};
// @lc code=end
