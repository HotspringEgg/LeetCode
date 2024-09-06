#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int result = 0;
    unordered_map<int, Employee*> IdMap;

    void addValue(Employee *employee)
    {
        result += employee->importance;
        if (employee->subordinates.empty())
        {
            return;
        }

        for (int i = 0; i < employee->subordinates.size(); i++)
        {
            addValue(IdMap[employee->subordinates[i]]);
        }
    }

    int getImportance(vector<Employee *> employees, int id)
    {
        // int n = employees.size();
        for (int i = 0; i < employees.size(); i++)
        {
            IdMap[employees[i]->id] = employees[i];
        }

        addValue(IdMap[id]);

        return result;
    }
};
// @lc code=end
