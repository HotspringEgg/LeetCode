#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // int maxPro = 0;
        // int minPri = __INT32_MAX__;
        // for (int i = 0; i < prices.size(); i++)
        // {
        //     minPri = min(minPri, prices[i]);
        //     maxPro = max(prices[i] - minPri, maxPro);
        // }
        // return maxPro;

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
            // 之前买和现在买相比，取最大现金
            dp[i][0] = max(dp[i - 1][0], -prices[i]);

            // 之前卖和现在卖相比，取最大现金
            // 股票当前价值+前一天所持现金
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }

        return dp[n - 1][1];
    }
};
// @lc code=end
