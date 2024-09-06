/*
 * @lc app=leetcode.cn id=3154 lang=cpp
 *
 * [3154] 到达第 K 级台阶的方案数
 */

// @lc code=start
class Solution
{
public:
    int comb(int m, int n)
    {
        if (n > m)
            return 0;
        if (n == 0 || n == m)
            return 1;

        long long result = 1;
        for (int i = 1; i <= n; ++i)
        {
            result *= m - i + 1;
            result /= i;
        }
        return result;
    }

    int waysToReachStair(int k)
    {
        // 向上n次
        int n = 0;
        // 向上n次的同时可以向下n+1次
        // 对n次求和为2的n方 - 1 ，最多减(n + 1）
        // 初始位置是1， 所以范围在[2 ^ n - n - 1, 2 ^ n]

        // 起始位置
        int maxLoc = 1;
        int minLoc = maxLoc - n - 1;
        int ans = 0;
        while (true)
        {
            if (k <= maxLoc && k >= minLoc)
            {
                int num = maxLoc - k;
                ans += comb(n + 1, num);
            }
            else if (k < minLoc)
            {
                break;
            }
            n++;
            maxLoc *= 2;
            minLoc = maxLoc - n - 1;
        }

        return ans;
    }
};
// @lc code=end
