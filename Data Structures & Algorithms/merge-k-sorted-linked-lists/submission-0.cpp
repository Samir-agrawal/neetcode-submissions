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
    struct comp{
        bool operator()(ListNode* l1,ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> minHeap;
        int k = lists.size();
        for(int i=0;i<k;i++) 
            if(lists[i]!=nullptr) 
                minHeap.push(lists[i]);
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while(!minHeap.empty())
        {
            ListNode* node = minHeap.top();
            minHeap.pop();
            if(node->next != nullptr) minHeap.push(node->next);
            tail->next = node;
            tail = tail->next;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
