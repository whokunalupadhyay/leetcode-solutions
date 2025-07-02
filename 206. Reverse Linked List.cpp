class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(!head) return nullptr;

        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr){
            ListNode* front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
        
    }
};