//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends


class Solution {
public:
    Node* mergeTwoLists(Node* l1, Node* l2) {
        Node dummy(0);
        Node* current = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->data < l2->data) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // Append the remaining nodes from either list
        if (l1 != nullptr) {
            current->next = l1;
        } else {
            current->next = l2;
        }

        return dummy.next;
    }

    Node* mergeKLists(Node* arr[], int K) {
        if (K == 0) {
            return nullptr;
        }

        int interval = 1;

        // Continue merging pairs until there is only one merged list remaining
        while (interval < K) {
            for (int i = 0; i < K - interval; i += interval * 2) {
                arr[i] = mergeTwoLists(arr[i], arr[i + interval]);
            }
            interval *= 2;
        }
        return arr[0];
    }
};

// class Solution {
// public:
//     // Function to merge K sorted linked list.
//     Node* mergeKLists(Node* arr[], int K) {
//         map<int, int> freqMap;
//         // Count the frequency of each element in the linked lists
//         for (int i = 0; i < K; i++) {
//             Node* temp = arr[i];
//             while (temp != NULL) {
//                 freqMap[temp->data]++;
//                 temp = temp->next;
//             }
//         }
//         Node* dummy = new Node(-1);
//         Node* curr = dummy;

//         // Create the merged linked list using the frequency information
//         for (auto it : freqMap) {
//             int value = it.first;
//             int frequency = it.second;
//             while (frequency--) {
//                 curr->next = new Node(value);
//                 curr = curr->next;
//             }
//         }
//         return dummy->next;
//     }
// };



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends