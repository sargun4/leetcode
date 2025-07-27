 class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        ListNode*slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){//get to mid of ll, for even sized ll, mid is left node
            slow=slow->next;
            fast=fast->next->next;
        }        
        slow->next=revLL(slow->next);
        
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val){
                return false;
            }
            head=head->next;
            slow=slow->next;;
        }
        return true;
    }
    ListNode*revLL(ListNode*head){
        ListNode *prev=NULL;
        ListNode *next=NULL;
        ListNode *curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};