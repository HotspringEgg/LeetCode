/*
 * @lc app=leetcode.cn id=3133 lang=cpp
 *
 * [3133] 数组最后一个元素的最小值
 */

// @lc code=start
class Solution
{
public:
    long long minEnd(int n, int x)
    {
        // 计算 x 的有效位数
        int bitCount = 64 - __builtin_clz(x);
        long long res = x;
        long long m = n - 1;
        int j = 0;
        for (int i = 0; i < bitCount; ++i)
        {
            if (((res >> i) & 1) == 0)
            {
                if ((m >> j) & 1)
                {
                    res |= (1LL << i);
                }
                j++;
            }
        }
        return res;
    }
};
// @lc code=end
