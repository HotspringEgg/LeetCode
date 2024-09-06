#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        unordered_set<int> set;
        int sum = 0;
        sum = getSum(n);
        while (true)
        {
            if (sum == 1)
            {
                return true;
            }
            else
            {
                if (set.find(sum) == set.end())
                {
                    set.insert(sum);
                    sum = getSum(sum);
                }
                else
                {
                    return false;
                }
            }
        }
        return false;
    }
};
// @lc code=end
// int getSum(int n)
// {
//     int sum = 0;
//     while (n)
//     {
//         sum += (n % 10) * (n % 10);
//         n /= 10;
//     }
//     return sum;
// }

// bool isHappy(int n)
// {
//     unordered_set<int> set;
//     while (true)
//     {
//         int sum = getSum(n);
//         if (sum == 1)
//         {
//             return true;
//         }
//         else
//         {
//             if (set.find(sum) != set.end())
//             {
//                 return false;
//             }
//             else
//             {
//                 set.insert(sum);
//                 n = getSum(sum);
//             }
//         }
//     }
//     return false;
// }