#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> result;
        vector<int> output;
        for (int i = 0; i < nums.size(); i++)
        {
            if (result.find(nums[i]) == result.end())
            {
                result.insert(pair<int, int>(target - nums[i], i));
            }else
            {
                output.push_back(result[nums[i]]);
                output.push_back(i);
                break;
            }
        }
        return output;
    }
};
// @lc code=end
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     unordered_map<int, int> result;
//     vector<int> output;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (result.find(target - nums[i]) != result.end())
//         {
//             output.push_back(result[target - nums[i]]);
//             output.push_back(i);
//             break;
//         }
//         result.insert(pair<int, int>(nums[i], i));
//     }
//     return output;
// }
