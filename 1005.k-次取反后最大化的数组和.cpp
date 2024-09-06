/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        int result = 0;
        // 1.按照绝对值排列数组
        sort(nums.begin(), nums.end(), cmp);

        // 2.反转最大的负数
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && k > 0)
            {
                nums[i] *= -1;
                k--;
            }
        }

        // 3.根据剩余k的数字反转最小的正数
        k = k % 2;
        if (k)
        {
            nums[nums.size() - 1] *= -1;
        }
        // 4.累加
        for (int num : nums)
        {
            result += num;
        }
        return result;
    }
};
// @lc code=end
