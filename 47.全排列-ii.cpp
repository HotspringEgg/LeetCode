/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        // uset集合是可以阻止for循环中选择重复的元素，而不能阻止递归中出现重复的元素
        unordered_set<int> uset;

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == true || uset.find(nums[i]) != uset.end())
            {
                continue;
            }

            uset.insert(nums[i]);
            used[i] = true;
            path.push_back(nums[i]);

            backtracking(nums, used);

            // 同层查重不需要每个循环将其erase
            // uset.erase(nums[i]);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
// @lc code=end
