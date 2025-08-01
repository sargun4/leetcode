//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/
class Solution {
public:
    // Node *merge(Node *l1, Node *l2){
    //     if(l1 == NULL) return l2;
    //     if(l2 == NULL) return l1;
    //     if(l1 -> data > l2 -> data){
    //         swap(l1, l2);
    //     }
    //     Node *head = l1;
    //     while(l1 != NULL && l2 != NULL){
    //         Node *temp = NULL;
    //         while(l1 != NULL && l1 -> data <= l2 -> data){
    //             temp = l1;
    //             l1 = l1 -> bottom;
    //         }
    //         temp -> bottom = l2;
    //         swap(l1 , l2);
    //     }
    //     return head;
    // }
        
Node* merge(Node* h1, Node* h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1; 
    Node* result = NULL; 
    if (h1->data < h2->data) {
        result = h1;
        result->bottom = merge(h1->bottom, h2);
    } else {
        result = h2;
        result->bottom = merge(h1, h2->bottom);
    } 
    return result;
}

Node* flatten(Node* root) {
    if (root == NULL || root->next == NULL) return root; 
    Node* h1 = root;
    Node* h2 = root->next; 
    while (h2 != NULL) {
        Node* h2sNext = h2->next; 
        // Merge the two levels
        h1 = merge(h1, h2); 
        // Move to the next level
        h2 = h2sNext;
    } 
    return h1;
}

};

//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node * temp = NULL;
        struct Node * head = NULL;
        struct Node * pre = NULL;
        struct Node * tempB = NULL;
        struct Node * preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Solution ob;
        Node* root = ob.flatten(head);
        printList(root);
        cout << endl;

    }
    return 0;
}

// } Driver Code Ends