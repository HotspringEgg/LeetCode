/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast ++){

            if(nums[fast] != nums[slow]){
                slow++;
                nums[slow] = nums[fast];
            }

        }
        return slow + 1;

    }
};
// @lc code=end

