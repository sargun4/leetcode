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
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++


class Solution{
    public:
    Node* rev(Node* head){
        if (head == NULL || head->next == NULL) return head;
        Node* curr = head; Node* prev=NULL;
        Node* temp;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    Node* addOne(Node *head){
        Node* l1=head;
        Node* l2=new Node(1);

        l1=rev(l1); l2=rev(l2);
 
        Node* ans=new Node(0); 
        int sum=0;
        int carry=0;
        while (l1 != NULL || l2!=NULL){
            if(l1!=NULL){
                sum+=l1->data;
                l1=l1->next;
            }if(l2!=NULL){
                sum+=l2->data;
                l2=l2->next;
            }
            ans->data=sum%10;
            carry=sum/10;
            Node* newnode=new Node(carry);
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
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends