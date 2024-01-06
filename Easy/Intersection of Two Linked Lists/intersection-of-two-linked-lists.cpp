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
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}


// } Driver Code Ends



class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        map<int, int> mp;
        // Populate the map with elements from the second linked list
        while (head2 != NULL) {
            mp[head2->data]++;
            head2 = head2->next;
        }
        // Traverse the first linked list
        while (head1 != NULL) {
            if (mp.find(head1->data) != mp.end()) { // Element is present in the second linked list
                Node *n = new Node(head1->data);
                temp->next = n;
                temp = n;
            }
            head1 = head1->next;
        }
       return dummy->next;
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
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends