//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int data) {
            this->data = data;  // Correct assignment
            left = right = NULL;
        }
    };
    
    vector<int> ans;  // To store the leaf nodes
    
    vector<int> leafNodes(int arr[], int N) {
        Node* root = NULL;  // Start with an empty tree
        for (int i = 0; i < N; i++) {
            root = build(root, arr[i]);
        }
        ans.clear();  // Clear the ans vector for fresh use
        traverse(root);
        return ans;
    }
    
    void traverse(Node* root) {
        if (root == NULL) return;
        traverse(root->left);
        if (root->left == NULL && root->right == NULL) {  // Check for leaf node
            ans.push_back(root->data);
        }
        traverse(root->right);  // Correctly traverse right child
    }
    
    Node* build(Node* root, int val) {
        if (root == NULL) {
            return new Node(val);  // Create a new node if root is null
        }
        if (root->data < val) {
            root->right = build(root->right, val);
        } else if (root->data > val) {
            root->left = build(root->left, val);
        }
        return root;
    }
};
 

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends