//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */


//  find the middle node  of the linked list 
// Reverse the linked list from mid node to last node . mid node should point to NULL.
// Now take 2 pointers first pointer to the last node and another to the head node 
// and manipulate the list as required in the question till the first pointer don't point the null.
class Solution{ 
public:
    Node *reverse(Node *head){
        Node *prev = NULL, *next = NULL;
        Node *curr = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(Node* head) {
        Node *slow = head;
        Node *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }//get to mid nodes
        Node *temp = slow->next;
        slow->next = NULL;
        Node *second = reverse(temp);//reverse 2nd half
        Node *first = head;
        while(first && second){
            Node *temp1 = first;
            Node *temp2= second;
            first = first->next;
            second = second->next;
            temp1->next = temp2;
            temp2->next = first;
        }
    }
};
 



//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends