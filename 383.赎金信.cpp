#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int record[26] = {0};
        for (int i = 0; i < magazine.size(); i++)
        {
            record[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (record[ransomNote[i] - 'a'] == 0)
            {
                return false;
            }
            record[ransomNote[i] - 'a']--;
        }

        return true;
    }
};
// @lc code=end
// bool canConstruct(string ransomNote, string magazine)
// {
//     int record[26] = {0};

//     if (ransomNote.length() > magazine.length())
//     {
//         return false;
//     }

//     for (int i = 0; i < magazine.length(); i++)
//     {
//         record[magazine[i] - 'a']++;
//     }

//     for (int i = 0; i < ransomNote.length(); i++)
//     {
//         record[ransomNote[i] - 'a']--;
//         if (record[ransomNote[i] - 'a'] < 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }