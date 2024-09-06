#include <vector>
#include <unordered_set>

using namespace std;
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<bool> used)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        // used集合是可以阻止for循环中选择重复的元素，而不能阻止递归中出现重复的元素
        // unordered_set<int> used;

        for (int i = 0; i < nums.size(); i++)
        {
            // if (used.find(nums[i]) != used.end())
            // {
            //     continue;
            // }

            if (used[i] == true)
            {
                continue;
            }

            // used.insert(nums[i]);
            used[i] = true;
            path.push_back(nums[i]);

            backtracking(nums, used);

            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
// @lc code=end
