class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* lprev = nullptr;
        ListNode* curr = head; 
        // Move to the node just before the reversal starts
        for (int i = 1; i < left; i++) {
            lprev = curr;
            curr = curr->next;
        } 
        // Store the start and end of the reversal
        ListNode* l = curr;
        ListNode* r = head;
        for (int i = 1; i <= right; i++) {
            r = r->next;
        } 
        // Reverse the nodes in the range [left, right]
        ListNode* temp;
        ListNode* prev = nullptr;
        for (int i = left; i <= right; i++) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        } 
        // Connect the reversed part back to the original list
        if (lprev) {
            lprev->next = prev;
        } else {
            head = prev;
        }
        l->next = curr; 
        return head;
    }
};
