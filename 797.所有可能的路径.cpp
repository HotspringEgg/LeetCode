#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int start, int target, vector<vector<int>> &graph)
    {
        if (start == target)
        {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < graph[start].size(); i++)
        {
            path.push_back(graph[start][i]);
            backtracking(graph[start][i], target, graph);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        result.clear();
        path.clear();

        int target = graph.size() - 1;
        path.push_back(0);
        backtracking(0, target, graph);
        return result;
    }
};
// @lc code=end
