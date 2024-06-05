//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

 

// https://www.geeksforgeeks.org/problems/maximum-winning-score--170637/1?page=1&category=Linked%20List,Binary%20Search%20Tree&status=unsolved&sortBy=accuracy
// As we can se this problem is same as maximum sum path from root to leaf.
// so we will use level order traversal technique 

class Solution {
  public:
    //Function to return maximum path product from any node in a tree.
    long long findMaxScore(Node* root){
        long long res=1;
        queue<pair<Node*,long long>>q;
        q.push({root,root->data});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;++i){
                auto p=q.front();
                Node* node=p.first;
                long long val=p.second;
                q.pop();
                if(!node->left && !node->right){//when we reach leaf node, calc max prod
                    res=max(res,val);
                }
                if(node->left){
                    long long temp=(node->left->data)*val;
                    q.push({node->left,temp});
                }
                if(node->right){
                    long long temp=(node->right->data)*val;
                    q.push({node->right,temp});
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.


int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        cout << ob.findMaxScore(root) << "\n";
    }


    return 0;
}
// } Driver Code Ends