struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) {
        return head;
    }    
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;
    // Move to the left position
    for (int i = 1; i < left; i++) {
        prev = prev->next;
        curr = curr->next;
    }
    // Reverse the sublist from left to right
    for (int i = 0; i < right - left; i++) {
        struct ListNode* temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }
    head = dummy->next;
    free(dummy);
    return head;
}