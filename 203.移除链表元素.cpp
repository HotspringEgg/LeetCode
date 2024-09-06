/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode dummyHead = ListNode(0, head);
        ListNode *cur = &dummyHead;
        while (cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                cur->next = cur->next->next;
                // cur = cur->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummyHead.next;
    }
};
// @lc code=end
// 定义虚拟头节点指向原头节点
// ListNode* dummyHead = new ListNode(0, head);

// ListNode* cur = dummyHead;

// while (cur->next != NULL)
// {
//     if (cur->next->val == val)
//     {
//         ListNode* tmp = cur->next;
//         cur->next = cur->next->next;
//         delete tmp;
//     }else
//     {
//         cur = cur->next;
//     }
// }

// head = dummyHead->next;
// delete dummyHead;
// return head;
