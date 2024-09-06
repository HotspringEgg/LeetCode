/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        //滑动窗口
        set<long> window;
        for (int i = 0; i < nums.size(); i++)
        {
            //保证窗口大小
            if (i > indexDiff)
            {
                window.erase(nums[i - indexDiff - 1]);
            }
            //查找窗口中是否有符合条件的元素
            auto it = window.lower_bound((long)nums[i] - valueDiff);
            if (it != window.end() && *it <= (long)nums[i] + valueDiff)
            {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

