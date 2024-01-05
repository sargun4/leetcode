
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr=head;
        int size=0;
        while(curr!=NULL){
            curr=curr->next;
            size++;
        }
        
        cout<<size;
        int frmbeg=k;
        int frmend=size-k+1; //kth node frm end

        ListNode* n1=head;
        while(--frmbeg){
            n1=n1->next;
        }
 
        ListNode* n2=head;
        while(--frmend){
            n2=n2->next;
        }
          
        cout<<n1->val<<endl;
        cout<<n2->val<<endl;

        ListNode* temp=new ListNode(0);
        temp->val=n1->val;
        n1->val=n2->val;
        n2->val=temp->val;

        return head;
    }
};