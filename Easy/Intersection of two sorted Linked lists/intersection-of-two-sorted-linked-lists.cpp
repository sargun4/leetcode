//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends


class Solution{ 
    public:
    Node* findIntersection(Node* head1, Node* head2){
        if(head1==NULL || head2==NULL) return NULL;
        Node* curr1=head1;
        Node* curr2=head2;
        curr1=head1;
        curr2=head2;

        Node* newhead=new Node(0);//head of new LL
        Node* curr=newhead;
        // Traverse both linked lists until one of them reaches the end
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->data == curr2->data) {
                // If the data of both nodes is the same, add it to the result linked list
                curr->next = new Node(curr1->data);
                curr = curr->next;
                curr1 = curr1->next;
                curr2 = curr2->next;
            } else if (curr1->data < curr2->data) {
                // If data in the first linked list is smaller, move the pointer in the first linked list
                curr1 = curr1->next;
            } else {
                // If data in the second linked list is smaller, move the pointer in the second linked list
                curr2 = curr2->next;
            }
        }
        // Return the head of the result linked list (excluding the newhead node)
        return newhead->next;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends