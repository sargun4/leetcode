class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL ||head->next==NULL){
            return head;
        }
        ListNode* temp=head->next;
        head->next=swapPairs(head->next->next);
        temp->next=head;
        return temp;
    }
};
// class Solution {
// public:
//     ListNode* revknodes(ListNode* head, int k) {
//         ListNode* prev = NULL;
//         ListNode* curr = head;
//         ListNode* temp;
//         int ctr = 0; 
//         // Count the number of nodes in the current k-group
//         ListNode* countNode = head;
//         while (ctr < k && countNode != NULL) {
//             countNode = countNode->next;
//             ctr++;
//         } 
//         // If there are at least k nodes, proceed with reversal
//         if (ctr == k) {
//             ctr = 0;
//             while (curr != NULL && ctr < k) {
//                 temp = curr->next;
//                 curr->next = prev;
//                 prev = curr;
//                 curr = temp;
//                 ctr++;
//             } 
//             if (temp != NULL) {
//                 // Recursively reverse the next k nodes
//                 head->next = revknodes(temp, k);
//             }
//         } else {
//             // If there are less than k nodes, reverse them back to maintain order
//             while (prev != NULL) {
//                 temp = prev->next;
//                 prev->next = curr;
//                 curr = prev;
//                 prev = temp;
//             }
//             return curr;
//         } 
//         return prev;
//     } 
//     ListNode* swapPairs(ListNode* head) {
//         // Call revknodes with k=2 to reverse every 2 nodes
//         head = revknodes(head, 2);
//         return head;
//     }
// };
