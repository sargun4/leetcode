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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) { // lvlorder-bfs
        vector<int> ans;
        if (!root)
            return ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            if (node == NULL)
                ans.push_back(-1);
            else
                ans.push_back(node->data);
            if (node != NULL) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A) {
        if (A.size() == 0)
            return NULL; 
        Node *root = new Node(A[0]);
        queue<Node *> q;
        q.push(root); 
        for (int i = 1; i < A.size(); i += 2) {
            Node *current = q.front();
            q.pop(); 
            if (A[i] != -1) {
                current->left = new Node(A[i]);
                q.push(current->left);
            } 
            if (i + 1 < A.size() && A[i + 1] != -1) {
                current->right = new Node(A[i + 1]);
                q.push(current->right);
            }
        }

        return root;
    }
};
 

//{ Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node* node)  
{  
    if (node == NULL) return;  
  
    /* first delete both subtrees */
    _deleteTree(node->left);  
    _deleteTree(node->right);  
  
    /* then delete the node */
    //cout << "Deleting node: " << node->data << endl;  
    delete node;  
}  
  
/* Deletes a tree and sets the root as NULL */
void deleteTree(Node** node_ref)  
{  
    _deleteTree(*node_ref);  
    *node_ref = NULL;  
}  

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        
        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node* temp = root;
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        if(!getRoot && temp){
            cout<<"-1"<<endl;
        }else if(getRoot && !temp){
            cout<<"-1"<<endl;
        }
        inorder(getRoot);
        
        cout << "\n";

    }


    return 0;
}
// } Driver Code Ends