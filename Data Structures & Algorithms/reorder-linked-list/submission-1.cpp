/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    ListNode* reverseLL(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode *prev = nullptr, *curr = head;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l1 = head;
        ListNode *l2 = reverseLL(slow->next);
        slow->next = nullptr;

        ListNode *ptr1 = l1, *ptr2 = l2;
        while(ptr2)
        {
            ListNode* next1 = ptr1->next;
            ListNode* next2 = ptr2->next;

            ptr1->next = ptr2;
            ptr2->next = next1;

            ptr1 = next1;
            ptr2 = next2;
        }
    }
};
