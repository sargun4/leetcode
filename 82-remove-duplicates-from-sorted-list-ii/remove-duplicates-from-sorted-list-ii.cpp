class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->val==curr->next->val){//dupliacte found
                while(curr->next!=NULL && curr->val==curr->next->val){
                    curr=curr->next;//skip all the duplicates
                }
                prev->next=curr->next;
            }else{
                prev=prev->next;//move to next unique node
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};
// trav the list using two pointers: prev (last confirmed unique node) and curr (current node being inspected)
// If curr.val == curr.next.val, skip all nodes with the same value
// Otherwise, move prev forward
// Return the list starting from dummy.next
