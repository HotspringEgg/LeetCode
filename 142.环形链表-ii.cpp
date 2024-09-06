/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 */

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                break;
            }
        }

        if (fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }

        ListNode *cur = head;
        while (cur != slow)
        {
            cur = cur->next;
            slow = slow->next;
        }

        return cur;
    }
};
// @lc code=end

// // ListNode* dummyHead(0);
// // dummyHead->next = head;
// ListNode* fast = head;
// ListNode* slow = head;
// while (fast != nullptr && fast->next != nullptr)
// {
//     fast = fast->next->next;
//     slow = slow->next;
//     if(fast == slow)
//     {
//         break;
//         // ListNode* index1 = head;
//         // ListNode* index2 = fast;
//         // // int i = 0;
//         // while (index1 != index2)
//         // {
//         //     index1 = index1->next;
//         //     index2 = index2->next;
//         //     // i++;
//         // }
//         // return index1;
//     }
// }

// if (fast == nullptr || fast->next == nullptr) {
//     return nullptr;
// }

// ListNode* index1 = head;
// ListNode* index2 = fast;
// // int i = 0;
// while (index1 != index2)
// {
//     index1 = index1->next;
//     index2 = index2->next;
//     // i++;
// }
// return index1;

// // return nullptr;
