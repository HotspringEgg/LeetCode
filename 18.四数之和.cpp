#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] > target && nums[k] >= 0)
            {
                break;
            }

            if (k > 0 && nums[k] == nums[k - 1])
            {
                continue;
            }

            for (int i = k + 1; i < nums.size(); i++)
            {
                if (nums[k] + nums[i] > target && nums[i] >= 0)
                {
                    break;
                }

                if (i > k + 1 && nums[i] == nums[i - 1])
                {
                    continue;
                }//此处忘了改成k+1

                int left = i + 1;
                int right = nums.size() - 1;

                while (left < right)
                {
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else
                    {
                        // The result being pushed to the vector should be the combination of the four numbers, not their sum.
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1])
                        {
                            left++;
                        }
                        if (left < right && nums[right] == nums[right + 1])
                        {
                            right--;
                        }
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
