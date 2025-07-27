class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* prev=NULL; ListNode* curr=head; ListNode* temp;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* AddTwoNums(ListNode* l1,ListNode* l2){
        int sum=0;
        int carry=0;
        ListNode* ans=new ListNode(0);
        while(l1!=NULL || l2!=NULL){
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
            ListNode* node=new ListNode(carry);
            node->next=ans;
            ans=node;
            sum=carry;
        }
        if(carry==1) return rev(ans);
        else return rev(ans->next);
    }
    ListNode* doubleIt(ListNode* head) {
        // Reverse the list to start from LSB
        head = rev(head);
        // Double the number by adding it to itself
        ListNode* doubled = AddTwoNums(head, head);
        // Reverse again to get MSB to LSB
        return rev(doubled);
    }
};