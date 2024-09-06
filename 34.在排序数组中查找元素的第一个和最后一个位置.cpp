/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
        if (rightBorder - leftBorder >= 1) return {leftBorder, rightBorder - 1};
        return {-1, -1};
    }

    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int leftBorder = -2;
        while (left < right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] >= target) {
                right = mid;
                leftBorder = right;
            } else {
                left = mid + 1;
            }
        }
        return leftBorder;
    }

    int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int rightBorder = -2;
        while (left < right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
};
// @lc code=end

