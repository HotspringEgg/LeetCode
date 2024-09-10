#include <vector>
#include <deque>
using namespace std;
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution
{
public:
    deque<int> que;
    void push(int val)
    {
        while (!que.empty() && val > que.back())
        {
            que.pop_back();
        }
        que.push_back(val);
    }

    void pop(int val)
    {
        if (!que.empty() && que.front() == val)
        {
            que.pop_front();
        }
    }

    int front()
    {
        return que.front();
    }

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            // 填入元素
            push(nums[i]);
        }
        result.push_back(front());
        for (int i = k; i < nums.size(); i++)
        {
            // 弹出队首元素，因为其生命周期结束
            pop(nums[i - k]);
            // 填入元素
            push(nums[i]);
            result.push_back(front());
        }
        return result;
    }
};
// @lc code=end
// class Solution
// {
// private:
//     deque<int> que;
//     void pop(int value)
//     {
//         if (!que.empty() && value == que.front())
//         {
//             que.pop_front();
//         }
//     }

//     void push(int value)
//     {
//         while (!que.empty() && value > que.back())
//         {
//             que.pop_back();
//         }
//         que.push_back(value);
//     }

//     int front()
//     {
//         return que.front();
//     }

// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         vector<int> result;
//         for (int i = 0; i < k; i++)
//         {
//             push(nums[i]);
//         }

//         result.push_back(front());

//         for (int i = k; i < nums.size(); i++)
//         {
//             pop(nums[i - k]); // nums[i - k]生命周期必须结束
//             push(nums[i]);
//             result.push_back(front());
//         }
//         return result;
//     }
// };