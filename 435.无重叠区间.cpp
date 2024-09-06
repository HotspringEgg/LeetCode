/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // 考虑数组为空
        if (intervals.empty())
        {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), cmp);
        //“独立区间”个数
        int count = 1;
        int arrow = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            // 确定相切或者相离的区间
            if (arrow <= intervals[i][0])
            {
                count++;
                arrow = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};
// @lc code=end
