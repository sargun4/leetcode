//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

vector<int> take(int n){
    vector<int> ans(n);
    for(int i=0;i<n;i++) cin>>ans[i];
    return ans;
}

Node* inputList(int size, vector<int> v)
{
    if(size==0) return NULL;
    
    int val = v[0];
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        val = v[i+1];
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    srand(time(0));
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        int p = rand()%3;
        
        vector<int> v1 = take(n1);
        vector<int> v2 = take(n2);
        vector<int> v3 = take(n3);
        
        
        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* common = NULL;
        
        if(p==0){
            common = inputList(n3, v3);
            head1 = inputList(n1, v1);
            head2 = inputList(n2, v2);
        }
        else if(p==1){
            
            head1 = inputList(n1, v1);
            common = inputList(n3, v3);
            head2 = inputList(n2, v2);
        }
         else{
            
            head1 = inputList(n1, v1);
            head2 = inputList(n2, v2);
            common = inputList(n3, v3);
        }
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends



//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2){
    int a=0,b=0;//a=len(LL 1), b=len(LL 2)
    Node* temp1 = head1;
    while (temp1 != NULL){
        a++;
        temp1=temp1->next;
    }
    Node* temp2 = head2;
    while (temp2 != NULL){
        b++;
        temp2 = temp2->next;
    }
    //Now we can calculate the difference between length of the linked lists and then travers
    //the longer list by that much times and then start comparing both lists node by node.
    int diff=abs(a-b);
    if(a<b){
        while (diff--){
            head2=head2->next;
        }
    }else{
        while (diff--){
            head1=head1->next;
        }
    }
    //Now compare the common node from here onwards
    while (head1!=NULL && head2!=NULL ){
        if(head1==head2){
            return head1->data;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return -1;//if LLs dont intrsect at any pt
}

