#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution
{
public:
    //static关键字使得cmp函数成为静态成员函数
    //使其不依赖于任何Solution类的对象
    //可以直接传递给std::sort等需要普通函数或静态成员函数的标准库算法 
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }

        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> queue;
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); i++)
        {
            int position = people[i][1];
            queue.insert(queue.begin() + position, people[i]);
        }
        return queue;
    }
};
// @lc code=end
