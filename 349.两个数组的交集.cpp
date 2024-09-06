#include<unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] ?????????????????????????????????
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); i++)
        {
            if (nums_set.find(nums2[i]) != nums_set.end())
            {
                result_set.insert(nums2[i]);
            }
        }
        vector<int> result(result_set.begin(), result_set.end());
        return result;
    }
};
// @lc code=end

// unordered_set<int> result_set;
// unordered_set<int> nums_set(nums1.begin(), nums1.end());
// for (int num : nums2)
// {
//     if (nums_set.find(num) != nums_set.end())
//     {
//         result_set.insert(num);
//     }
// }
// vector<int> result(result_set.begin(), result_set.end());
// return result;