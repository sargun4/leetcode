class Solution {
public:
    ListNode* rev(ListNode* head){
        if(!head||!head->next){
            return head;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* temp;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=rev(l1); l2=rev(l2);
        int sum=0;
        int carry=0;
        ListNode* ans=new ListNode(0);
        while(l1!=NULL||l2!=NULL){
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            ans->val=sum%10;
            carry=sum/10;
            ListNode* node= new ListNode(carry);
            node->next=ans;
            ans=node;
            sum=carry;
        }
        if(carry==0){
            return ans->next;
        }else{
            return ans;
        }
    }
};