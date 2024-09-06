#include <vector>
#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // int result = INT32_MIN;
        // int count = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     count += nums[i];
        //     result = count > result ? count : result;
        //     if (count < 0)
        //     {
        //         count = 0;
        //     }
        // }
        // return result;

        if (nums.size() == 0)
        {
            return 0;
            /* code */
        }

        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];

        int result = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};
// @lc code=end
