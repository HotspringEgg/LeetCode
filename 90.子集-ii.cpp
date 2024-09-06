/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, int startIndex)
    {
        result.push_back(path);
        // 本题为收集所有子集，要收集所有节点，而不是只针对叶子节点
        if (startIndex >= nums.size())
        {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > startIndex && nums[i] == nums[i - 1])
            {
                continue;
            }

            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    // void backtracking(vector<int> &nums, int startIndex)
    // {
    //     result.push_back(path);
    //     该集合用来记录哪些元素已经被横向遍历过
    //     如果被横向遍历过就跳过
    //     unordered_set<int> uset;
    //     for (int i = startIndex; i < nums.size(); i++)
    //     {
    //         find后迭代器若==end()则说明不包含
    //         if (uset.find(nums[i]) != uset.end())
    //         {
    //             continue;
    //         }
    //         uset.insert(nums[i]);
    //         path.push_back(nums[i]);
    //         backtracking(nums, i + 1);
    //         path.pop_back();
    //     }
    // }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // 去重需要排序
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end
