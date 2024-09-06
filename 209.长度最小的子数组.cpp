#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int sum = 0;
        int subLen = 0;
        int result = nums.size() + 1;
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                subLen = right - left + 1;
                result = min(result, subLen);
                
                sum -= nums[left];
                left++;
            }
        }
        return result == nums.size() + 1 ? 0 : result;

        // 第一版
        // nums = {2,3,1,2,4,3};
        // target = 7;
        // int minL = nums.size() + 1;
        // int i = 0;
        // int sum = 0;
        // int subL = 0;

        // for (int j = 0; j < nums.size(); j++)
        // {
        //     sum += nums[j];
        //     while (sum >= target)
        //     {
        //         subL = j - i + 1;
        //         minL = min(minL, subL);
        //         sum -= nums[i]; // 这里注意要减去第i位元素
        //         i++;
        //     }
        // }

        // return minL == (nums.size() + 1) ? 0 : minL; // 注意是==号
    }
};
// @lc code=end
