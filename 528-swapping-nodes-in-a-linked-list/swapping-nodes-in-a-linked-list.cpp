
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr=head;
        int len=0;
        while(curr!=NULL){
            curr=curr->next;
            len++;
        }
        
        // cout<<len;
        int frmbeg=k; //kth node frm beignin
        int frmend=len-k+1; //kth node frm end

        ListNode* n1=head;
        while(--frmbeg){
            n1=n1->next;
        }
 
        ListNode* n2=head;
        while(--frmend){
            n2=n2->next;
        }
          
        // cout<<n1->val<<endl;
        // cout<<n2->val<<endl;

        ListNode* temp=new ListNode(0);
        //jsut swap the vals,not the nodes
        temp->val=n1->val;
        n1->val=n2->val;
        n2->val=temp->val;

        return head;
    }
};