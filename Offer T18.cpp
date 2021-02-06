class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *node = new ListNode(0);
        node->next = head;
        ListNode *pre = node,*cur = head;
        while(cur){
            if(cur->val == val){
                pre->next = cur->next;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        return node->next;
    }
};