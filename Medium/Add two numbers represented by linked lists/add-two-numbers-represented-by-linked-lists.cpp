//{ Driver Code Starts
// driver

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


// } Driver Code Ends

class Solution{
public:
    Node* rev(Node* head){
        if (head == NULL || head->next == NULL) return head;
        Node* curr=head;
        Node* prev=NULL;
        Node* temp;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second){
        Node* l1=rev(first);
        Node* l2=rev(second);
        int sum=0;
        int carry=0;
        Node* ans=new Node(0);
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL){
                sum+=l1->data;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->data;
                l2=l2->next;
            }
            ans->data=sum%10;
            carry=sum/10;
            Node* newnode= new Node(carry);
            newnode->next=ans;
            ans=newnode;
            sum=carry;
        }
        if(carry==0){
            return ans->next;
        }else{
            return ans;
        }
    }
};


//{ Driver Code Starts.

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
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends