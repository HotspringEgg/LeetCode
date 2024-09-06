/*
 * @lc app=leetcode.cn id=3007 lang=cpp
 *
 * [3007] 价值和小于等于 K 的最大数字
 */

// @lc code=start
class Solution
{
public:
    long long accumulatedBitPrice(int x, long long num)
    {
        long long period = 1LL << x;
        long long res = period / 2 * (num / period);
        if (num % period >= period / 2)
        {
            res += num % period - (period / 2 - 1);
        }
        return res;
    }

    long long accumulatedPrice(int x, long long num)
    {
        long long res = 0;
        int length = 64 - __builtin_clzll(num);
        for (int i = x; i <= length; i += x)
        {
            res += accumulatedBitPrice(i, num);
        }
        return res;
    }

    long long findMaximumNumber(long long k, int x)
    {
        long long left = 1;
        long long right = (k + 1) << x;
        while (left < right)
        {
            long long mid = (left + right) / 2;
            if (accumulatedPrice(x, mid) > k)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};
// @lc code=end
