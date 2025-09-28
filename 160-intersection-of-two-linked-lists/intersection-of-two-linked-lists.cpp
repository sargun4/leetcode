// // #1
// // Time Complexity : O(m + n)
// // Space Complexity : O(m)
// class Solution {
// public:
//     ListNode*getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* curr=headA;
//         unordered_set<ListNode*> addr_set;
//         while(curr!=NULL){
//             addr_set.insert(curr);
//             curr=curr->next;
//         }
//         curr=headB;
//         ListNode*intersecnode=NULL;
//         while(curr!=NULL){
//             if(addr_set.find(curr)!=addr_set.end()){
//                 intersecnode=curr;
//                 break;
//             }
//             curr=curr->next;
//         }
//         return intersecnode;
//     }
// };
// #2
// Time Complexity : O(m + n)
// Space Complexity : O(1)
class Solution { 
public:
    ListNode*getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*curr=headA;
        int a=0,b=0;//a=len(1st LL), b=len(2nd LL)
        while (curr!=NULL){
            a++;
            curr=curr->next;
        }
        curr=headB;
        while (curr!=NULL){
            b++;
            curr=curr->next;
        }
        int diff=abs(a-b);
        if(a<b){
            while(diff--){
                headB=headB->next;
            }
        }else{
            while(diff--){
                headA=headA->next;
            }
        }
        while(headA && headB){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};
 