class Solution {
public:
    ListNode* rev(ListNode* head){
        if(!head) return head;
        ListNode* prev=NULL; ListNode* curr=head; ListNode* temp;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        // if grp_len % 2==0 then rev the nodes
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        //loop for getting len of grps
        for(int len=1;len<1e5 && head;len++){
            ListNode* tail=head;
            ListNode* nexthead;
            int ctr=1;
            //len of curr grp
            while(ctr<len && tail && tail->next){
                tail=tail->next;
                ctr++;
            }
            nexthead=tail->next;//head of next grp
            if((ctr%2==0)){//even len grp- rev these
                tail->next=NULL;//cut grp
                prev->next=rev(head);//rev n attach it to prev
                prev=head;//move prev to end of the rev grp
                head->next=nexthead;//link end of rev grp to nxt grp
                head=nexthead;//move head to next grp
            }else{//if odd size,jus go to nextgrp
                prev=tail;
                head=nexthead;
            }
        }
        return dummy->next; //head
    }
};