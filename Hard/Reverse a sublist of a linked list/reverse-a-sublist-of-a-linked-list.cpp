//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends

class Solution {
public:
    Node* reverseBetween(Node* head, int m, int n) {
        Node* mprev = NULL;
        Node* nnext = NULL;
        Node* curr = head;
        // Move to the mth node
        for (int i = 1; i < m; i++) {
            mprev = curr;
            curr = curr->next;
        }
        Node* mthNode = curr;
        // Reverse the sub-list between m and n
        Node* prev = NULL;
        for (int i = m; i <= n; i++) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // Update pointers
        if (mprev != NULL) {
            mprev->next = prev;
        } else {
            head = prev;
        }
        mthNode->next = curr;
        return head;
    }
};


//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends