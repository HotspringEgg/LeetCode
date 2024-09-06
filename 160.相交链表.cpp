#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0;
        int lenB = 0;
        while (curA != nullptr)
        {
            curA = curA->next;
            lenA++;
        }
        while (curB != nullptr)
        {
            curB = curB->next;
            lenB++;
        }

        curA = headA;
        curB = headB;

        if (lenA < lenB)
        {
            // 此处交换节点
            swap(curA, curB);
        }

        // 此处求绝对值
        int gap = abs(lenA - lenB);

        while (gap--)
        {
            curA = curA->next;
        }

        while (curA != nullptr)
        {
            if (curA == curB)
            {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};
// @lc code=end
// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
// {
//     ListNode *curA = headA;
//     ListNode *curB = headB;
//     int lenA = 0, lenB = 0;
//     while (curA != nullptr)
//     {
//         curA = curA->next;
//         lenA++;
//     }
//     while (curB != nullptr)
//     {
//         lenB++;
//         curB = curB->next;
//     }

//     curA = headA;
//     curB = headB;

//     if (lenA < lenB)
//     {
//         // swap(lenA, lenB);
//         swap(curA, curB);
//     }

//     int gap = abs(lenA - lenB);

//     while (gap > 0)
//     {
//         curA = curA->next;
//         gap--;
//     }

//     while (curA != nullptr)
//     {
//         if (curA == curB)
//         {
//             return curA;
//         }
//         curA = curA->next;
//         curB = curB->next;
//     }
//     return nullptr;
// }