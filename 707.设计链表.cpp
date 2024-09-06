/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int val)
            : val(val), next(nullptr)
        {
        }
    };

    MyLinkedList()
    {
        dummyHead = new ListNode(0);
        size = 0;
    }

    int get(int index)
    {
        if (index >= size || index < 0)
        {
            return -1;
        }

        ListNode *cur = dummyHead->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        size++;
    }

    void addAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        ListNode *cur = dummyHead;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size || index < 0)
        {
            return;
        }

        ListNode *newNode = new ListNode(val);
        ListNode *cur = dummyHead;
        while (index--)
        {
            cur = cur->next;
        }

        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
        {
            return;
        }

        ListNode *cur = dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        ListNode *temp = cur->next;

        cur->next = temp->next;
        delete temp;
        size--;
    }

private:
    ListNode *dummyHead;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

//     struct ListNode
//     {
//         int val;
//         ListNode* next;
//         ListNode(int val)
//         : val(val)
//         , next(nullptr)
//         {}
//     };

//     MyLinkedList()
//     {
//         dummyHead = new ListNode(0);
//         size = 0;
//     }

//     int get(int index)
//     {
//         //下标无效
//         if (index >= size || index < 0)
//         {
//             return -1;
//         }

//         ListNode* cur = dummyHead->next;
//         while (index--)
//         {
//             cur = cur->next;
//         }

//         return cur->val;
//     }

//     void addAtHead(int val)
//     {
//         ListNode* newNode = new ListNode(val);
//         newNode->next = dummyHead->next;
//         dummyHead->next = newNode;
//         size++;
//     }

//     void addAtTail(int val)
//     {
//         ListNode* newNode = new ListNode(val);
//         ListNode* cur = dummyHead;

//         while (cur->next != nullptr)
//         {
//             cur = cur->next;
//         }

//         cur->next = newNode;
//         size++;
//     }

//     void addAtIndex(int index, int val)
//     {
//         //下标无效
//         if (index > size || index < 0)
//         {
//             return;
//         }

//         ListNode* newNode = new ListNode(val);
//         ListNode* cur = dummyHead;

//         while (index--)
//         {
//             cur = cur->next;
//         }

//         newNode->next = cur->next;
//         cur->next = newNode;
//         size++;
//         return;
//     }

//     void deleteAtIndex(int index)
//     {
//         if (index >= size || index < 0)
//         {
//             return;
//         }

//         ListNode* cur = dummyHead;

//         while (index--)
//         {
//             cur = cur->next;
//         }

//         ListNode* tmp = cur->next;
//         cur->next = cur->next->next;
//         delete tmp;
//         size--;
//         return;
//     }

// private:
//     ListNode* dummyHead;
//     int size;
