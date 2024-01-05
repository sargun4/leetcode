//rec
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverseList(head, NULL);
    }
    ListNode* reverseList(ListNode* curr, ListNode* prev) {
        if(curr == NULL) return prev;
        ListNode* temp = curr->next;
        curr->next = prev;
        return reverseList(temp, curr);
    }
};
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* curr=head;
//         ListNode* prev=NULL;
//         ListNode* temp=NULL;
//         while(curr!=NULL){
//             temp=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=temp;
//         }
//         return prev;
//     }
// };