//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


 Node* reverse(Node* head){
     if(head==NULL || head->next==NULL) return head;
     Node* tmp=reverse(head->next);
     head->next->next=head;
     head->next=NULL;
     return tmp;
 }
 Node* merge(Node* l1,Node* l2){
     if(!l1) return l2;
     if(!l2) return l1;
     if(l1->data<=l2->data){
         l1->next=merge(l1->next,l2);
         return l1;
     }
     else{
         l2->next=merge(l1,l2->next);
         return l2;
     }
 }
void sort(Node **head){
      Node* i=*head;
      Node* d=i->next;
      Node* dc=d;
      while(d && d->next){
          i->next=i->next->next;
          d->next=d->next->next;
          i=i->next;
          d=d->next;
      }
      i->next=NULL;
      *head=merge(*head,reverse(dc));
 }
