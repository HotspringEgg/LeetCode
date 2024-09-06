#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution
{
public:
    // 记录每天的三种状态及其相互转化规则
    // 1.   持股状态0，可由非冷冻状态购买股票以及保持原装转化
    // 2.   冷冻状态1，可由抛售昨日持股以及抛售今日持股转化
    // 3. 非冷冻状态2，可由冷冻状态以及保持原状转化
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }

        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};
// @lc code=end