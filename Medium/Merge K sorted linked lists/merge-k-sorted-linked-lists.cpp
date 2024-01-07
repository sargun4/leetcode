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
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->data <= l2->data){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }else{
            l2->next=mergeTwoLists(l2->next,l1);
            return l2;
        }
        return NULL;
    }
    Node* partitionNmerge(int start,int end,Node* arr[]){
        // base case
        if (start > end) return NULL;
        if (start == end) return arr[start];
        int mid=start+(end-start)/2;
        Node* l1=partitionNmerge(start,mid,arr);
        Node* l2=partitionNmerge(mid+1,end,arr);
        return mergeTwoLists(l1,l2);
    }
    Node* mergeKLists(Node* arr[], int K) {
        if(K==0) return NULL;
        return partitionNmerge(0,K-1,arr);
    }
};

// class Solution {
// public:
//     Node* mergeTwoLists(Node* l1, Node* l2) {
//         Node dummy(0);
//         Node* curr = &dummy;
//         while (l1 != NULL && l2 != NULL) {
//             if (l1->data < l2->data) {
//                 curr->next = l1;
//                 l1 = l1->next;
//             } else {
//                 curr->next = l2;
//                 l2 = l2->next;
//             }
//             curr = curr->next;
//         }
//         // Append the remaining nodes from either list
//         if (l1 != NULL) {
//             curr->next = l1;
//         } else {
//             curr->next = l2;
//         }
//         return dummy.next;
//     }
//     Node* mergeKLists(Node* arr[], int K) {
//         if (K == 0) {
//             return NULL;
//         }
//         int interval = 1;
//         // Continue merging pairs until there is only one merged list remaining
//         while (interval < K) {
//             for (int i = 0; i < K - interval; i += interval * 2) {
//                 arr[i] = mergeTwoLists(arr[i], arr[i + interval]);
//             }
//             interval *= 2;
//         }
//         return arr[0];
//     }
// };

// //TLe
// // class Solution {
// // public:
// //     // Function to merge K sorted linked list.
// //     Node* mergeKLists(Node* arr[], int K) {
// //         map<int, int> freqMap;
// //         // Count the frequency of each element in the linked lists
// //         for (int i = 0; i < K; i++) {
// //             Node* temp = arr[i];
// //             while (temp != NULL) {
// //                 freqMap[temp->data]++;
// //                 temp = temp->next;
// //             }
// //         }
// //         Node* dummy = new Node(-1);
// //         Node* curr = dummy;

// //         // Create the merged linked list using the frequency information
// //         for (auto it : freqMap) {
// //             int value = it.first;
// //             int frequency = it.second;
// //             while (frequency--) {
// //                 curr->next = new Node(value);
// //                 curr = curr->next;
// //             }
// //         }
// //         return dummy->next;
// //     }
// // };




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