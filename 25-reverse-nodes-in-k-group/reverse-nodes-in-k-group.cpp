class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp;
        int ctr = 0;
        // Count the number of nodes in the current group
        ListNode* countNodes = head;
        int count = 0;
        while (countNodes != NULL && count < k) {
            countNodes = countNodes->next;
            count++;
        }
        // If the current group has less than k nodes, return head
        if (count < k) {
            return head;
        }
        // Reverse the current group
        while (curr != NULL && ctr < k) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            ctr++;
        }
        // Update head to the new reversed group
        head->next = reverseKGroup(curr, k);
        // Return the new head of the reversed group
        return prev;
    }
};

// // class Solution {
// // public:
// //     ListNode* reverseKGroup(ListNode* head, int k) {
// //         if(head==NULL||k==1) return head;
// //         ListNode*dummy=new ListNode(0);
// //         dummy->next=head;
// //         ListNode*curr=dummy,*next=dummy,*prev=dummy;
// //         int ctr=0;
// //         while(curr->next!=NULL){
// //             curr=curr->next;
// //             ctr++;
// //         }
// //         while(ctr>=k){
// //             curr=prev->next;
// //             next=curr->next;
// //             for(int i=1;i<k;i++){
// //                 curr->next=next->next;
// //                 next->next=prev->next;
// //                 prev->next=next;
// //                 next=curr->next;
// //             }
// //             prev=curr;
// //             ctr-=k;
// //         }
// //         return dummy->next;
// //     }
// // };
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* curr = head;
//         int ctr = 0;
//         // Count the number of nodes
//         while (curr != NULL && ctr < k) {
//             curr = curr->next;
//             ctr++;
//         }
//         // If there are at least k nodes, reverse them
//         if (ctr == k) {
//             curr = reverseKGroup(curr, k); // Recursively reverse the remaining nodes
//             // Reverse the current group of k nodes
//             while (ctr > 0) {
//                 ListNode* temp = head->next;
//                 head->next = curr;
//                 curr = head;
//                 head = temp;
//                 ctr--;
//             }
//             head = curr; // Update the new head of the reversed group
//         }
//         return head;
//     }
// };
