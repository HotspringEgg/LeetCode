#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // int result = 0;
        // for (int i = 1; i < prices.size(); i++)
        // {
        //     if (prices[i] - prices[i - 1] > 0)
        //     {
        //         result += prices[i] - prices[i - 1];
        //     }
        // }

        // return result;

        int n = prices.size();
        // 定义dp数组
        // dp[i][0]代表最高"持股后现金"
        // dp[i][1]代表最高"抛股后现金"
        vector<vector<int>> dp(n, {0, 0});
        // 初始化
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; i++)
        {
            // dp[i][0]：在第 i 天持有股票的最大利润，可以由以下两种情况转移得到：
            // 1. 前一天买了保持前一天的状态 2. 前一天没买今天买
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            // dp[i][1]：在第 i 天不持有股票的最大利润，可以由以下两种情况转移得到：
            // 1. 前一天没买保持前一天的状态 2. 前一天买了今天卖
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }

        return dp[n - 1][1];
    }
};
// @lc code=end
