class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode *ptr1 = l1, *ptr2 = l2, *ptr = dummy;
        int carry = 0;

        while (ptr1 != nullptr || ptr2 != nullptr || carry > 0)
        {
            int sum = carry; 
            
            if (ptr1 != nullptr) {
                sum += ptr1->val;
                ptr1 = ptr1->next; 
            }
            
            if (ptr2 != nullptr) {
                sum += ptr2->val;
                ptr2 = ptr2->next; 
            }
            
            carry = sum / 10;        
            int digit = sum % 10;    
            
            ptr->next = new ListNode(digit);
            ptr = ptr->next;
        }
        
        ListNode* head = dummy->next;
        delete dummy; 

        return head;
    }
};
