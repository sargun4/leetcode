//{ Driver Code Starts
// Initial Template for C++// C program to find n'th Node in linked list
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    // Function to reverse a linked list.
    struct Node* reverseList(struct Node* head) {
        // code here
        // return head of reversed list
    }
};


//{ Driver Code Starts.

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Driver program to test above function*/
int main() {
    int T, n, l, firstdata;
    cin >> T;

    while (T--) {
        struct Node *head = NULL, *tail = NULL;

        cin >> n;

        if (n != 0) {
            cin >> firstdata;
            head = new Node(firstdata);
            tail = head;
        }

        for (int i = 1; i < n; i++) {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        Solution ob;
        head = ob.reverseList(head);

        printList(head);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends