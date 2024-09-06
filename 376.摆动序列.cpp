#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int index = 1;
        int preDiff = 0, curDiff = 0;

        if (nums.size() <= 1)
        {
            return nums.size();
        }

        for (int i = 0; i < nums.size() - 1; i++)
        {
            /* code */
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff >= 0 && curDiff < 0) || (preDiff <= 0 && curDiff > 0))
            {
                index++;
                preDiff = curDiff;
            }
        }

        return index;
    }
};
// @lc code=end
