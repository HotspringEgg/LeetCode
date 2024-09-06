#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }

        vector<int> dp(nums.size(), 1);

        int result = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

                result = max(result, dp[i]);
            }
            
        }

        return result;
    }
};
// @lc code=end
