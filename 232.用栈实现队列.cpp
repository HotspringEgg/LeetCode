#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
    // 队列可以分为两个栈
    // ↑------- ↓
    // ←   |    ←
    //  -------
public:
    stack<int> in;
    stack<int> out;

    MyQueue()
    {
    }

    void push(int val)
    {
        in.push(val);
    }

    int pop()
    {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        int result = out.top();
        out.pop();
        return result;
    }

    int peek()
    {
        int top = pop();
        out.push(top);
        return top;
    }
    
    bool empty()
    {
        return (in.empty() && out.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
// stack<int> in;
// stack<int> out;

// MyQueue()
// {
// }

// void push(int x)
// {
//     in.push(x);
// }

// int pop()
// {
//     int result = 0;
//     if (out.empty())
//     {
//         while (!in.empty())
//         {
//             out.push(in.top());
//             in.pop();
//         }
//     }

//     result = out.top();
//     out.pop();
//     return result;
// }

// int peek()
// {
//     int result = pop();
//     out.push(result);
//     return result;
// }

// bool empty()
// {
//     bool result = (in.empty() && out.empty());
//     return result;
// }