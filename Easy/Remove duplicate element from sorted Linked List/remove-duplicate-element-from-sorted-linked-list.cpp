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


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends



Node* removeDuplicates(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = head;
    Node* curr = head->next;
    while (curr != NULL) {
        if (prev->data == curr->data) {
            Node* temp = curr;
            curr = curr->next;
            prev->next = curr;
            delete temp;  // Free the memory of the duplicate node
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
