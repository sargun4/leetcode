
class Solution {
public:
    ListNode* revknodes(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = NULL;
        int ctr = 0;
        // rev first k nodes of the linked list
        while (curr != NULL && ctr < k){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            ctr++;
        }
        // Now head points to the kth node. Recursively call for the LL starting from curr node.
        //& make rest of the LL as next of the first node
        if (temp != NULL) {
            head->next = revknodes(temp, k);
        }
        //prev is the new head of the reversed group
        return prev;
    } 
    ListNode* swapPairs(ListNode* head) {
        //swapping pairs, so k = 2
        return revknodes(head, 2);
    }
}; 
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head==NULL ||head->next==NULL){
//             return head;
//         }
//         ListNode* temp=head->next;
//         head->next=swapPairs(head->next->next);
//         temp->next=head;
//         return temp;
//     }
// };
 
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if (!head || !head->next) return head;
//         ListNode *temp = new ListNode(0,head);
//         ListNode *curr = head;
//         ListNode *prev = temp;
//         while(curr && curr->next){
//             prev->next = curr->next;
//             curr->next = prev->next->next;
//             prev->next->next = curr;
//             prev = curr;
//             curr = curr->next;
//         }
//         return temp->next;
//     }
// }; 