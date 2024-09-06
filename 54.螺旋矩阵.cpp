/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
        {
            return {};
        }
        
        //m为行数n为列数
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;

        //下标
        int top = 0;//上边界
        int bot = m - 1;//下边界
        int left = 0;//左边界
        int right = n - 1;//右边界
        
        //每次处理完一个边界后，剩余的未处理部分就变成了一个更小的矩阵，直到所有元素都被读取。
        while (top <= bot && left <= right)
        {
            //遍历上边界
            if(top <= bot)
            {
                for (int i = left; i <= right; i++)
                {
                    res.push_back(matrix[top][i]);
                }
                top++;
            }

            //遍历右边界
            if(left <= right)
            {
                for (int i = top; i <= bot; i++)
                {
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
           
            //遍历下边界
            if(top <= bot)
            {
                for (int i = right; i >= left; i--)
                {
                    res.push_back(matrix[bot][i]);
                }
                bot--;
            }  
            
            //遍历左边界
            if(left <= right)
            {
                for (int i = bot; i >= top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }

            //缩圈
            // top++;
            // right--;
            // bot--;
            // left++;
        }
        

        return res;
    }
};
// @lc code=end