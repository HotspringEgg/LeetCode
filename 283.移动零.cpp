/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1) {
			return;
		}

        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast ++){
            if(nums[fast] !=0 ){
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;
                slow ++;
            }
        }
    }
};
// @lc code=end

