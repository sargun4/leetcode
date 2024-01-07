//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

// Find the middle of the linked list using the slow and fast pointer technique.
// Recursively divide the linked list into two halves until there is only one node in each half.
// Merge the sorted halves back together to obtain the sorted linked list.
 
class Solution {
public:
    Node* mergeSorting(Node** head) {
        Node* curr=*head;
        Node*first;
        Node*second;
        if(!curr || !(curr->next)) return nullptr;
        findMiddle(curr,&first,&second);
        mergeSorting(&first);
        mergeSorting(&second);
        *head = merge2lls(first, second);
    }
    Node* merge2lls(Node*first,Node*second){
        Node* ans=NULL;
        if(!first) return second;
        else if (!second) return first;
        if (first->data <= second->data ){
            ans = first;
            ans -> next = merge2lls(first->next , second);
        }
        else{
            ans = second;
            ans -> next = merge2lls(first, second->next);
        }
        return ans;
    }
    void findMiddle(Node* curr,Node**first,Node**second){
        Node* fast;Node*slow;
        slow=curr;
        fast=curr->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        *first=curr;
        *second=slow->next;
        slow->next=NULL;
    }

    Node* mergeSort(Node* head) { 
        mergeSorting(&head);
        return head;
    }
};



//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends