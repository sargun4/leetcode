//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
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
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends

class Solution{
public:
    Node* divide(int N, Node *head){
        if (N == 0 || head == NULL || head->next == NULL) return head;
        Node* odd=new Node(-1);
        Node* oddHead=odd; //store oddhead
        Node* even=new Node(-1);
        Node* evenHead=even;//store evenhead
        Node* curr=head;
        while(curr!=NULL){
            if(curr->data%2!=0){
                odd->next=new Node(curr->data);
                odd=odd->next;
                curr=curr->next;
            }else{
                even->next=new Node(curr->data);
                even=even->next;
                curr=curr->next;
            }
        }
        odd->next=NULL;
        even->next=oddHead->next;
        head=evenHead->next;
        delete(evenHead);
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends