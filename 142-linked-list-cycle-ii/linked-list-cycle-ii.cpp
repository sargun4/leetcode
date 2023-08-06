#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode*detectCycle(ListNode *head) {
        if(head==NULL|| head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(slow!=fast) return NULL;
        ListNode* p=head;
        while(p!=slow){
            p=p->next;
            slow=slow->next;
        }
        return p;
    }
};
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         if(head==NULL||head->next==NULL) return NULL;
//         ListNode*slow=head,*fast=head,*entry=head;
//         while(fast->next && fast->next->next){
//             slow=slow->next;
//             fast=fast->next->next;
//             if(slow==fast){ //cycle exists
//                 while(slow!=entry){ //found entry location
//                     slow=slow->next;
//                     entry=entry->next;
//                 }
//                 return entry;
//             }
//         }
//         return NULL;
//     }
// };