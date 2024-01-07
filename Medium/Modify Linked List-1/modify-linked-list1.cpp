//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends

 
class Solution{
    public:
    Node* revknodes(Node*head,int k){
        if (head == NULL || head->next==NULL) return head;
        Node *prev=NULL; Node*curr=head; Node*temp;
        int ctr=0;
        while(curr!=NULL&&ctr<k){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            ctr++;
        }
        if(temp!=NULL){
            head=revknodes(temp,k);
        }
        return prev;
    }
    struct Node* modifyTheList(struct Node *head){
        int n=0;
        Node*curr=head;
        while(curr!=NULL){
            curr=curr->next;
            n++;
        }
        curr=head;
        head=revknodes(curr,n); 
        
        // print(head);
        
        Node* fast=head;
        Node* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        // cout<<slow->data<<endl;
        // cout<<fast->data<<endl;
        
        Node* curr2=slow->next;
        Node* head2=curr2;
        slow->next=NULL;
        Node* curr1=head;
        
        // cout<<curr1->data<<endl;
        // cout<<curr2->data<<endl;
        
        head2=revknodes(head2,n/2);
        // cout<<head2->data<<endl; 
        curr2=head2;
        // cout<<curr2->data<<endl; 
        while(curr2!=NULL){
            curr1->data=(curr1->data)-(curr2->data);
            curr1=curr1->next;
            curr2=curr2->next;
        }
        head2=revknodes(head2,n/2);
        slow->next=head2;
        return head; 
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends