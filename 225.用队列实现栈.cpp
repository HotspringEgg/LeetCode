#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> que;
    // queue<int> que1;
    // queue<int> que2;

    MyStack() {

    }
    
    void push(int x) {
        // que1.push(x);
        que.push(x);
    }
    
    int pop() {
        // int len = que1.size();
        // len--;
        // while (len--)
        // {
        //     que2.push(que1.front());
        //     que1.pop();
        // }

        // int result = que1.front();

        // que1.pop();
        // que1 = que2;

        // while (!que2.empty())
        // {
        //     que2.pop();
        // }
        // return result;
        
        int len = que.size();
        len--;
        while (len--)
        {
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.pop();
        return result;
    }
    
    int top() {
        // int result = pop();
        // que1.push(result);
        // return result;
        int result = pop();
        que.push(result);
        return result;
    }
    
    bool empty() {
        return que.empty();
        // return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

