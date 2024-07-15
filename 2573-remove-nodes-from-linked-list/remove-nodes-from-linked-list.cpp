// Reverse the given linked list.
// Initialize a dummy node to hold the result.
// Traverse the reversed list, keeping nodes whose values are greater than or equal to the previous node's value.
// Reverse the resulting list to obtain the modified linked list.
// Return the head of the modified linked list.
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        //now prev is the head of the reversed ll

        curr = prev->next;
        prev->next = NULL;
        while (curr != NULL) {
            ListNode* temp = curr->next;
            if (curr->val >= prev->val) {
                curr->next = prev;
                prev = curr;
            }
            curr = temp;
        }
        return prev;
    }
};