#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>> &points)
    {
        // 考虑数组为空
        if (points.empty())
        {
            return 0;
        }

        int result = 1;
        sort(points.begin(), points.end(), cmp);
        int arrow = points[0][1];
        for (int i = 0; i < points.size(); i++)
        {
            // 可以射中
            if (arrow >= points[i][0] && arrow <= points[i][1])
            {
                continue;
            }
            else
            {
                result++;
                arrow = points[i][1];
            }
        }
        return result;
    }
};
// @lc code=end
