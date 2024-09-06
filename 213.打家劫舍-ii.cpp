/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // 考虑边缘情况
        if (nums.size() == 0)
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int n = nums.size();

        int result1 = robRange(nums, 0, n - 2);
        int result2 = robRange(nums, 1, n - 1);

        return max(result1, result2);
    }

    int robRange(vector<int> &nums, int start, int end)
    {
        // 考虑边缘情况
        if (start == end)
        {
            return nums[start];
        }

        int n = nums.size() - 1;
        vector<int> dp(n, 0);

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + start]);
        }

        return dp[n - 1];
    }
};
// @lc code=end
