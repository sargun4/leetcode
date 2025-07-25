//{ Driver Code Starts
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
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
public:
    set<int> s;
    bool check(Node *root, int l = 0){
        
        if(root == NULL) return true;
        if(!root->left && !root->right) s.insert(l);
        
        check(root->left, l+1);
        check(root->right, l+1 );
        
        return s.size() == 1;
    }
};
// class Solution {
// public:
//     unordered_map<int, Node*> lvlorder(Node* root) {
//         queue<Node*> q;
//         q.push(root);
//         unordered_map<int, Node*> map;
//         map[0] = root;
//         while (!q.empty()) {
//             int lvl = 0;
//             int n = q.size();
//             for (int i = 0; i < n; i++) {
//                 Node* node = q.front();
//                 q.pop();
//                 lvl++;
//                 if (isLeaf(node)) {
//                     map[lvl] = node;
//                 }
//                 if (node->left) q.push(node->left);
//                 if (node->right) q.push(node->right);
//             }
//         }
//         return map;
//     }

//     bool check(Node* root) {
//         unordered_map<int, Node*> map = lvlorder(root);
//         int firstLvl = 0;

//         for (auto it : map) {
//             int lvl = it.first;
//             Node* node = it.second;

//             if (firstLvl == 0) {
//                 firstLvl = lvl;
//             } else if (lvl != firstLvl) {
//                 return false;
//             }
//         }

//         return true;
//     }
//     bool isLeaf(Node* node) {
//         return (node && !node->left && !node->right);
//     }
// };


//{ Driver Code Starts.
// Driver program to test size function
int main()
{
    int t;
    cin>> t;
    getchar();
    while (t--)
    {
        string s;
        getline( cin, s );
        Node* head = buildTree( s );
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}

// } Driver Code Ends