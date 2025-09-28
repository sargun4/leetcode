 
class Solution {
public:
    // Function to find the middle of the list
    ListNode* middle(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge two sorted lists
    ListNode* mergeSortedLists(ListNode* p1, ListNode* p2) {
        ListNode dummy(0); // Dummy node to simplify code
        ListNode* curr = &dummy;
        while (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                curr->next = p1;
                p1 = p1->next;
            } else {
                curr->next = p2;
                p2 = p2->next;
            }
            curr = curr->next;
        }

        if (p1 != NULL) {
            curr->next = p1;
        } else {
            curr->next = p2;
        }

        return dummy.next;
    }

    // Function to sort the list using merge sort
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* mid = middle(head);
        ListNode* rightHead = mid->next;
        mid->next = NULL;

        ListNode* leftHalf = sortList(head);
        ListNode* rightHalf = sortList(rightHead);

        return mergeSortedLists(leftHalf, rightHalf);
    }
};
 