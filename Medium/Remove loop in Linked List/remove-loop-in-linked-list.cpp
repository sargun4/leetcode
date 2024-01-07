//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int>&myMap){
    
    while(head){
        if(myMap.find(head)==myMap.end()) return true;
        if(myMap[head] != (head->data)) return true;
        
        head=head->next;
    }
}




// } Driver Code Ends


class Solution {
public:
    void removeLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        // Detect the loop using Floyd's Cycle Detection Algorithm
        while (fast != NULL && fast->next != NULL) {
            // / Handle the case where the loop is formed by the last node connecting back to the head
            if(fast->next == head){
                fast->next = NULL;
                return;
            }
            
            if(slow->next == head){
                slow->next=NULL;
                return;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Loop detected, break from the loop
                break;
            }
        }
        // If no loop is present, return
        if (fast == NULL || fast->next == NULL) {
            return;
        }
        // Move one pointer back to the head
        slow = head;
        // Move both pointers one step at a time until they meet again
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        // Unlink the last node to remove the loop
        fast->next = NULL;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<Node *, int>myMap;
        
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        myMap[head]=num;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail]=num;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends