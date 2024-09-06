#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> maxProduct(n + 1);

        maxProduct[2] = 1;

        for (int i = 3; i < n + 1; i++)
        {
            for (int j = 1; j < i - 1; j++)
            {
                maxProduct[i] = max(maxProduct[i], max((j * (i - j)), j * maxProduct[i - j]));
            }
        }
        return maxProduct[n];
    }
};
// @lc code=end