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
        for (int i = 0; i < nums.size(); i++)
        {
            // 对于剪枝操作，本次target可能是负数，所以处理手法要做改变
            // （但其实不剪枝也不会超时）
            if (nums[i] > target && nums[i] >= 0)
            {
                // return result;
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++)
            {
                // 此处不可直接break
                if (nums[i] + nums[j] > target && nums[j] >= 0)
                {
                    // return result;
                    break;
                }

                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right)
                {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] == target)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while ((long)left < right && nums[left + 1] == nums[left])
                        {
                            left++;
                        }
                        while ((long)left < right && nums[right - 1] == nums[right])
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};
// @lc code=end
// vector<vector<int>> fourSum(vector<int> &nums, int target)
// {
//     vector<vector<int>> result;
//     sort(nums.begin(), nums.end());
//     for (int k = 0; k < nums.size(); k++)
//     {
//         if (nums[k] > target && nums[k] >= 0)
//         {
//             break;
//         }

//         if (k > 0 && nums[k] == nums[k - 1])
//         {
//             continue;
//         }

//         for (int i = k + 1; i < nums.size(); i++)
//         {
//             if (nums[k] + nums[i] > target && nums[i] >= 0)
//             {
//                 break;
//             }

//             if (i > k + 1 && nums[i] == nums[i - 1])
//             {
//                 continue;
//             } // 此处忘了改成k+1

//             int left = i + 1;
//             int right = nums.size() - 1;

//             while (left < right)
//             {
//                 if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
//                 {
//                     right--;
//                 }
//                 else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
//                 {
//                     left++;
//                 }
//                 else
//                 {
//                     // The result being pushed to the vector should be the combination of the four numbers, not their sum.
//                     result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
//                     left++;
//                     right--;
//                     while (left < right && nums[left] == nums[left - 1])
//                     {
//                         left++;
//                     }
//                     if (left < right && nums[right] == nums[right + 1])
//                     {
//                         right--;
//                     }
//                 }
//             }
//         }
//     }
//     return result;
// }