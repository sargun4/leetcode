// #include <bits/stdc++.h>
// using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// using stack
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr=head;
        while(curr){
            st.push(curr);
            curr=curr->next;
        }
        int k=st.size()/2;
        curr=head;
        while(k--){
            ListNode* topnode=st.top();
            st.pop();
            ListNode* temp=curr->next;
            curr->next=topnode;
            topnode->next=temp;
            curr=temp;
        }
        curr->next=NULL;
    }
};
//using reverseLL
// class Solution {
// public:
//     ListNode* revLL(ListNode* head){
//         ListNode* prev=NULL;
//         ListNode* curr=head;
//         ListNode* temp;
//         while(curr!=NULL){
//             temp=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=temp;
//         }
//         return prev;
//     }
//     void reorderList(ListNode* head) {
//         ListNode* slow=head;
//         ListNode* fast=head;
//         while(fast && fast->next){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         ListNode* rev=revLL(slow);
//         ListNode* curr=head;
//         while(rev->next!=NULL){
//             ListNode* tempcurr=curr->next;
//             curr->next=rev;
//             ListNode* temprev=rev->next;
//             rev->next=tempcurr;
//             curr=tempcurr;
//             rev=temprev;
//         }
//     }
// };