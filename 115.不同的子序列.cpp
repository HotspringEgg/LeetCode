#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1));
        for (int j = 0; j < t.size() + 1; j++)
        {
            dp[0][j] = 0;
        }
        
        for (int i = 0; i < s.size() + 1; i++)
        {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i < s.size() + 1; i++)
        {
            for (int j = 1; j < t.size() + 1; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};
// @lc code=end
