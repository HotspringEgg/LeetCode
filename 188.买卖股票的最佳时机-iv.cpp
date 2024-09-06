#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(2 * k, 0));

        for (int i = 0; i < k; i++)
        {
            dp[0][2 * i] = -prices[0];
        }

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            for (int j = 1; j < k; j++)
            {
                dp[i][2 * j] = max(dp[i - 1][2 * j], dp[i - 1][2 * j - 1] - prices[i]);
                dp[i][2 * j + 1] = max(dp[i - 1][2 * j + 1], dp[i - 1][2 * j] + prices[i]);
            }
        }
        return dp[n - 1][2 * k - 1];
    }
};
// @lc code=end
