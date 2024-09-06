#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        int leftSq = 0;
        int rightSq = 0;
        vector<int> newVec(nums.size(), 0);
        int newLoc = newVec.size() - 1;
        while (left <= right)
        {
            leftSq = nums[left] * nums[left];
            rightSq = nums[right] * nums[right];
            if (leftSq > rightSq)
            {
                newVec[newLoc] = leftSq;
                left++;
            }
            else
            {
                newVec[newLoc] = rightSq;
                right--;
            }
            newLoc--;
        }
        return newVec;
        
        // 第一版
        // int k = nums.size() - 1;
        // vector<int> result(nums.size(), 0);
        // for(int i = 0, j = nums.size() - 1; i  <= j;){
        //     if(nums[i] *nums[i] >= nums[j] *nums[j]){
        //         result[k] = nums[i] * nums[i];
        //         i++;
        //         k--;
        //     }else{
        //         result[k] = nums[j] * nums[j];
        //         j--;
        //         k--;
        //     }
        // }

        // return result;
    }
};
// @lc code=end
