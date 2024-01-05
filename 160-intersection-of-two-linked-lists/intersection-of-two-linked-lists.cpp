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
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if(headA==NULL||headB==NULL) return NULL;
//         ListNode *a=headA;
//         ListNode*b=headB;
//         //if a & b hv diff len,the we'll stop the loop after 2nd iteration
//         while(a!=b){
//             //for the end of the 1st iteration, we just reset the ptr to the head of the other LL
//             a=a==NULL ? headB:a->next;
//             b=b==NULL ? headA:b->next;
//         }
//         return a;
//     }
// };