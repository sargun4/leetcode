//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends

class Solution {
public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        set<int> s;
        
        // Insert elements from the first linked list into the set
        Node* curr1 = head1;
        while (curr1 != NULL) {
            s.insert(curr1->data);
            curr1 = curr1->next;
        }
        
        // Insert elements from the second linked list into the set
        Node* curr2 = head2;
        while (curr2 != NULL) {
            s.insert(curr2->data);
            curr2 = curr2->next;
        }

        // Create a dummy node for the result linked list
        Node* dummy = new Node(0);
        Node* curr = dummy;

        // Create new nodes for each element in the set and link them
        for (auto it = s.begin(); it != s.end(); ++it) {
            Node* newNode = new Node(*it);
            curr->next = newNode;
            curr = newNode;
        }

        // Return the head of the result linked list (excluding the dummy node)
        return dummy->next;
    }
};



//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends