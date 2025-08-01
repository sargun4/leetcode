//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */
 
class Solution{
    public: 
    int areMirror(Node* a, Node* b) {
        if(a == NULL and b == NULL){
            return 1;
        }
        if(a == NULL and b!= NULL){
            return 0;
        }
        if(a != NULL and b== NULL){
            return 0;
        }
        int a1 = areMirror(a->left , b->right);
        int a2 = areMirror(a->right , b->left);
        if(a1 and a2 and a->data == b->data){
            return 1;
        }
        else{
            return 0;
        }
    }
};
 
// class Solution{
// public:
//     // check for symmetric tree
//     bool isSymmetric(struct Node* root){
//         // Base case: null node is symmetric
//         if(root ==NULL)
//             return true;
//         // Recursive call: compare left subtree and right subtree
//         return isSymmetricUtil(root->left, root->right);
//     }
//     bool isSymmetricUtil(struct Node* left, struct Node* right){
//         // 1. Both null -> symmetric
//         if(left == NULL && right == NULL)
//             return true;
//         // 2. One null, the other not -> not symmetric
//         if(left == NULL || right == NULL)
//             return false;
//         // 3. Both not null, but different values -> not symmetric
//         if(left->data != right->data)
//             return false;
//         // Recursive call: check for symmetric tree with left child and right child
//         return isSymmetricUtil(left->left, right->right) && isSymmetricUtil(left->right, right->left);
//     }
// };

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);

        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);

        Solution ob;
        cout << ob.areMirror(root1, root2) << "\n";
    }
    return 0;
}
// } Driver Code Ends