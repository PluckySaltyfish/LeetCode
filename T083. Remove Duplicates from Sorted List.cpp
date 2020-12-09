class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        ListNode *last = head,*p = head->next;
        while(p){
            if(p->val == last->val){
                last->next = p->next;
            }
            else 
                last = p;
            p = p->next;
            
        }
        return head;
    }
};