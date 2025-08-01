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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
 
class Solution{
public:
    bool hasPathSum(Node *root, int s) {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL && root->data==s)
            return true;
        hasPathSum(root->left,s-root->data) || hasPathSum(root->right,s-root->data);
}
};
// class Solution:
//     def hasPathSum(self,root, S):
//         ans=[]
//         def solve(root,s):
//             s+=(root.data)
//             if not root.left and not root.right: #leaf node
//                 ans.append(s)
//                 return
//             if(root.right):
//                 solve(root.right,s)
//             if(root.left):
//                 solve(root.left,s)
//         solve(root,0)
//         # print(ans)
//         flag=0
//         for i in ans:
//             if i==S:
//                 flag=1
//                 break
//             else:
//                 flag=0
//         return flag

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int sum;
        scanf("%d ", &sum);
        Solution ob;
        cout << ob.hasPathSum(root, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends