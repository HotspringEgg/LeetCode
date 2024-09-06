/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(), mid = 0;
        // if (nums[0] == target)
        // {
        //     return 0;
        // }

        while (left < right)
        {
            mid = (left + right) / 2;

            if (nums[mid] > target)
            {
                right = mid;
            }
            else
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else return mid;
        }
        // cout << nums[left - 1];
        // return left > 1 && nums[left - 1] == target ? left - 1 : -1;
        return -1;
    }
};
// @lc code=end
