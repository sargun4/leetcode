//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node(new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		cout<<temp->data<<' ';
		temp = temp->next;
	}
	cout<<'\n';
}

void mergeList(struct Node **head1, struct Node **head2);

// Driver program to test above functions
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n1, n2, tmp;
        struct Node *a = NULL;
        struct Node *b = NULL;
        cin>>n1;
        while(n1--){
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>n2;
        while(n2--){
            cin>>tmp;
            push(&b, tmp);
        }
        mergeList(&a, &b);
        printList(a);
        printList(b);
    }
	return 0;
}

// } Driver Code Ends


void mergeList(struct Node **p, struct Node **q){
   Node* t1 = (*p), *t2 = (*q), *temp;
 while(t1 && t2){
   temp = t2->next;
   t2->next = t1->next;
   t1->next = t2;
   t1 = t2->next;
   t2 = temp;
   *q = t2;
 }

}