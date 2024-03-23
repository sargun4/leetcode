 #include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* revLL(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rev=revLL(slow);
        ListNode* curr=head;
        while(rev->next!=NULL){
            ListNode* tempcurr=curr->next;
            curr->next=rev;
            ListNode* temprev=rev->next;
            rev->next=tempcurr;
            curr=tempcurr;
            rev=temprev;
        }
    }
};