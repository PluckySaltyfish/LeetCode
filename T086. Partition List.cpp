class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *s = new ListNode(-1);
        ListNode *l = new ListNode(-1);
        ListNode *head0 = s;
        ListNode *head1 = l;
        ListNode *node = head;
        while(node){
            if(node->val < x){
                s->next = node;
                s = s->next;
            }
            else{
                l->next = node;
                l = l->next;
            }
            node = node->next;
        }
        l->next = NULL;
        s->next = head1->next;
        return head0->next;
    }
};