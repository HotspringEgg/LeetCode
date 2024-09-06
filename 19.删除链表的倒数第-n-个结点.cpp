/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *fast = head;
        ListNode *slow = dummyHead;
        
        while (--n)
        {
            fast = fast->next;
        }

        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *temp = slow->next->next;
        slow->next = temp;
        return dummyHead->next;
    }
};
// @lc code=end
// ListNode *dummyhead = new ListNode(0, head);
// ListNode *fast = dummyhead->next;
// ListNode *slow = dummyhead;
// // n++;
// while (n--)
// {
//     fast = fast->next;
// }

// while (fast != nullptr)
// {
//     slow = slow->next;
//     fast = fast->next;
// }

// ListNode *tmp = slow->next;
// slow->next = slow->next->next;
// delete tmp;

// return dummyhead->next;
