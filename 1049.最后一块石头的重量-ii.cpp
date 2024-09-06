/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeightII(vector<int> &nums)
    {
        int totalSize = nums.size();
        int sum = 0;

        // 对数组求和
        for (int i = 0; i < totalSize; i++)
        {
            sum += nums[i];
        }

        int target = sum / 2;

        vector<int> dp(target + 1, 0);

        // 目标是找到一个子集，使其元素的和等于 sum / 2。
        // 如果你把所有元素的重量都设为 1，
        // 背包的容量就相当于你可以选择多少个元素，
        // 但这与寻找特定数值的子集无关。

        // 先遍历物体
        for (int i = 0; i < totalSize; i++)
        {
            // 再遍历背包
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        return (sum - dp[target]) - dp[target];
    }
};
// @lc code=end
