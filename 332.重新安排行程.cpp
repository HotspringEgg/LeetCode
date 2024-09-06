#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution
{
public:
    int ticketNum = 0;
    // 门票信息包括始发地，目的地，数量，且目的地要按照字母顺序排列，故选择map
    //            始发地      目的地   数量
    unordered_map<string, map<string, int>> targets;
    vector<string> result;

    // 因为只要一个结果 所以返回值设置成bool即可
    bool backtracking()
    {
        if (result.size() == ticketNum + 1)
        {
            return true;
        }
        // 记录当前所在地
        string current = result.back();

        // 因为是unorder_map 所以可以直接索引到当前所在地
        // 优化写法
        // for (pair<const string, int> &target : targets[result[result.size() - 1]]){}
        for (auto it = targets[current].begin(); it != targets[current].end(); it++)
        {
            // 遍历到排序最靠前的有票的目的地
            if (it->second != 0)
            {
                // 将目的地加入结果集，并且去除该机票
                result.push_back(it->first);
                it->second--;

                // 回溯遍历该路线
                if (backtracking())
                {
                    return true;
                }

                //  该路线探寻失败，弹出该目的地，恢复机票数量
                result.pop_back();
                it->second++;
            }
        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // 记录总票数
        ticketNum = tickets.size();

        // 构建unordered_map
        for (int i = 0; i < tickets.size(); i++)
        {
            targets[tickets[i][0]][tickets[i][1]]++;
        }

        // 优化写法
        //  for (const vector<string> &vec : tickets)
        //  {
        //      targets[vec[0]][vec[1]]++; // 记录映射关系
        //  }

        // 起始机场
        result.push_back("JFK");
        backtracking();
        return result;
    }
};
// @lc code=end
