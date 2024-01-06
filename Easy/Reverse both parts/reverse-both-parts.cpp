//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends

class Solution{
public:
    Node* rev(Node* head){
      Node* prev=NULL;
      Node* curr=head;
      Node* temp;
      while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
      }
      return prev;
    }
    Node* reverse(Node *head, int k){
      if (head == NULL || head->next == NULL) return head;
      Node* curr=head;
      if(k==0){
        curr=rev(curr);
        return curr;
      }
      curr=head;

      Node*newhead;
      while(k--){
        newhead=curr;
        curr=curr->next;
      }
      newhead->next=NULL;
      newhead=rev(head);

      Node* secondPartHead=curr;
      while(curr!=NULL){
        curr=curr->next;//go till last node
      }
      curr=rev(secondPartHead);

      head->next=curr;
      return newhead;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends