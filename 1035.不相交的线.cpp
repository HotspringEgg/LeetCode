/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        // 直线不能相交，这就是说明在字符串A中 找到一个与字符串B相同的子序列，
        // 且这个子序列不能改变相对顺序，只要相对顺序不改变，链接相同数字的直线就不会相交。
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        for (int i = 1; i < nums1.size() + 1; i++)
        {
            for (int j = 1; j < nums2.size() + 1; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[nums1.size()][nums2.size()];
    }
};
// @lc code=end

