/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 */

class Solution
{
public:
    // ListNode *pre = nullptr;
    // ListNode *tmp = nullptr;

    ListNode *reverseList(ListNode *head, ListNode *tmp = nullptr, ListNode *pre = nullptr)
    {
        // 迭代法
        // ListNode *cur = head;
        // ListNode *pre = nullptr;
        // ListNode *tmp = nullptr;
        // while (cur)
        // {
        //     tmp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = tmp;
        // }
        // return pre;

        // 递归法
        if (head == nullptr)
        {
            return pre;
        }
        tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
        return reverseList(head, tmp, pre);
    }
};
// @lc code=end

// ListNode *reverse(ListNode *cur, ListNode *pre)
// {
//     if (!cur)
//     {
//         return pre;
//     }

//     ListNode *tmp = cur->next;
//     cur->next = pre;
//     return reverse(tmp, cur);
// }

// ListNode *reverseList(ListNode *head)
// {
// if (!head)
// {
//     return nullptr;
// }

// ListNode* cur = head;
// ListNode* pre = nullptr;

// while (cur)
// {
//     ListNode* tmp = cur->next;
//     cur->next = pre;
//     pre = cur;
//     cur = tmp;
// }
// return pre;
// return reverse(head, nullptr);
// }