#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int cover = 0;
        for (int i = 0; i <= cover; i++)
        {
            if (i > nums.size() - 1)
            {
                return true;
            }

            cover = max(nums[i] + i, cover);
            // if (nums[i])
            // {
            //     /* code */
            // }
        }
        return cover >= nums.size() - 1;
    }
};
// @lc code=end
