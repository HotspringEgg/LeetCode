#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                // 要判断当前的coins是否能组成j面值，若不能则跳过
                if (i >= coins[j] && dp[i - coins[j]] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];

        // vector<int> dp(amount + 1, INT_MAX);
        // dp[0] = 0;
        // for (int i = 0; i < coins.size(); i++)
        // { // 遍历物品
        //     for (int j = coins[i]; j <= amount; j++)
        //     { // 遍历背包
        //         if (dp[j - coins[i]] != INT_MAX)
        //         { // 如果dp[j - coins[i]]是初始值则跳过
        //             dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
        //         }
        //     }
        // }
        // if (dp[amount] == INT_MAX)
        //     return -1;
        // return dp[amount];
    }
};
// @lc code=end
