class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr=head, *prev=NULL;
        while(head!=NULL){
            if(head->val==val){
                if(!prev){
                    curr=curr->next;
                }else{
                    prev->next=head->next;
                }
            }else{
                prev=head;
            }
            head=head->next;
        }
        return curr;
    }
};