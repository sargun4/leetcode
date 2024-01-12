// class Solution {
// public:
//     int size(ListNode* curr){
//         int len=0;
//         while(curr!=NULL){
//             curr=curr->next;
//             len++;
//         }
//         return len;
//     }
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head==NULL){
//             return NULL;
//         }
//         int n = size(head);
//         int len=k%n;
//         len=n-len;
//         if(n==1||len==n){
//             return head;
//         }
//         int j=0;
//         ListNode *prev=head,*firstaddr=head;
//         while(prev!=NULL){
//             j++;
//             if(j==len){
//                 firstaddr=prev->next;
//                 prev->next=NULL;
//                 break;
//             }
//             prev=prev->next;
//         }
//         prev=firstaddr;
//         while(prev->next!=NULL){
//             prev=prev->next;
//         }
//         prev->next=head;
//         return firstaddr;
//     }
// };
class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        //find length of LL
        ListNode*curr=head;
        int len=1;
        while(curr->next!=NULL && ++len){
            curr=curr->next;
        }
        ///go till that node
        curr->next=head; //make last node(curr) point to head-make circular
        k=k%len;
        k=len-k;
        while(k--){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};
// // class Solution {
// // public:
// //     ListNode* rotateRight(ListNode* head, int k) {
// //        if(!head)
// //            return NULL;
// //         int n = 1;
// //         ListNode* tail = head;
// //         while(tail->next){
// //             n++;
// //             tail = tail->next;
// //         }
// //         tail->next = head;
// //         int size = n - k % n;
// //         for(int i = 0; i < size; i++){
// //             tail = tail->next;
// //         }  
// //         head = tail->next;
// //         tail->next = NULL;
// //         return head;
// //     }
// // };