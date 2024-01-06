//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends


class Solution{
    public:
    Node* rotateRight(Node* head, int k) {
        if(!head || !head->next || k==0) return head;
        //find length of LL
        Node*curr=head;
        int len=1;
        while(curr->next!=NULL && ++len){
            curr=curr->next;
        }
        ///go till that node
        curr->next=head; //make last node(curr) pint to head-make circular
        k=k%len;
        k=len-k;
        while(k--){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
    //Function to left rotate a linked list.
    Node* rotate(Node* head, int k){
        int len=0;
        Node* curr=head;
        while(curr!=NULL){
            curr=curr->next;
            len++;
        }
        int size=len-k;
        curr=head;
        curr=rotateRight(curr,size); //rotateright by len-k = rotateleft by k 
        return curr;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
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
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends