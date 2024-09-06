#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int step = 0;
        int curDis = 0;
        int nextDis = 0;
        if (nums.size() == 1)
        {
            return 0;
        }

        // 自己的思路
        // 遍历当前范围
        // for (int i = 0; i <= curDis; i++)
        // {
        //     // 取当前范围能达到的最大下标
        //     nextDis = max(nextDis, i + nums[i]);
        //     // 等于curDis时说明遍历结束，更新可执行范围并且步进
        //     if (i == curDis)
        //     {
        //         step++;
        //         curDis = nextDis;
        //     }

        //     // 如果当前范围大于数组最大下标，步进
        //     if (curDis >= nums.size() - 1)
        //     {
        //         step++;
        //         break;
        //     }
        // }

        
        for (int i = 0; i < nums.size(); i++)
        {
            nextDis = max(nextDis, i + nums[i]);
            if (i == curDis)
            {
                step++;
                curDis = nextDis;
                if (nextDis >= nums.size() - 1)
                {
                    break;
                }
            }
        }

        return step;
    }
};
// @lc code=end
