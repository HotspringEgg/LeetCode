#include <vector>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
public:
    class myComparison
    {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        // 熟悉大小顶堆的写法
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pri_que;

        for (auto it = map.begin(); it != map.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};
// @lc code=end
// class mycomparison
// {
// public:
//     bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
//     {
//         return lhs.second > rhs.second;
//     }
// };

// vector<int> topKFrequent(vector<int> &nums, int k)
// {
//     // 构建map，key为元素，value为其出现次数
//     unordered_map<int, int> map;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         map[nums[i]]++;
//     }

//     priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

//     for (auto it = map.begin(); it != map.end(); it++)
//     {
//         pri_que.push(*it);
//         if (pri_que.size() > k)
//         {
//             pri_que.pop();
//         }
//     }

//     // 因为后续要通过下标访问数组，所以要初始化其大小
//     vector<int> result(k);

//     for (int i = k - 1; i > -1; i--)
//     {
//         result[i] = pri_que.top().first;
//         pri_que.pop();
//     }
//     return result;
// }