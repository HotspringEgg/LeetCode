/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        // dp[i][j] ：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，
        // 最长重复子数组长度为dp[i][j]。
        // （特别注意： “以下标i - 1为结尾的A” 标明一定是 以A[i-1]为结尾的字符串 ）
        // eg: "3214" "4" "14" "214" "3214"
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;
        for (int i = 1; i < nums1.size() + 1; i++)
        {
            for (int j = 1; j < nums2.size() + 1; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};
// @lc code=end
