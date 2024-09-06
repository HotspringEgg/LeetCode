/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 考虑数组为空
        if (intervals.empty())
        {
            return {};
        }

        sort(intervals.begin(), intervals.end(), cmp);
        // “独立区间”个数

        vector<vector<int>> result;
        int left = intervals[0][0];
        int right = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            // 确定相切或者相交的区间
            if (right >= intervals[i][0])
            {
                // 更新右端点为两者的较大值
                right = max(intervals[i][1], right);
            }
            else
            {
                result.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        // 别忘了添加最后一个区间
        result.push_back({left, right});

        return result;
    }
};
// @lc code=end
