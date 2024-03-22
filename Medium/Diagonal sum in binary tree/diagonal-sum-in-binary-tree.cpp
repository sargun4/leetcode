//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
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
/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/

class Solution {
  public:
//Recursive c++ solution 
int height(Node *root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}
void func(vector<int>&v,Node *root,int level){
    if(root==NULL){
        return;
    }
    v[level]+=root->data;
    func(v,root->right,level);
    func(v,root->left,++level);
}
vector <int> diagonalSum(Node* root) {
    // Add your code here
    vector<int>v(height(root));
    func(v,root,0);
    vector<int>ans;
    for(int i=0;i<v.size();i++){
        if(v[i]==0)break;
        ans.push_back(v[i]);
    }
    return ans;
    }
};
// class Solution
// {
//     public:
//     void findSumOfDiagonal(Node *root, int ind, unordered_map<int, int> &mp)
//     {
//         if(root == nullptr)
//             return;
//         mp[ind] += root->data;
//         findSumOfDiagonal(root->left, ind + 1, mp);
//         findSumOfDiagonal(root->right, ind, mp);
//     }
//     vector <int> diagonalSum(Node* root) {
//         unordered_map<int, int> mp;
//         findSumOfDiagonal(root, 0, mp);
//         vector<int> ans(mp.size());
//         for(auto it : mp)
//             ans[it.first] = it.second;
//         return ans;
//     }
// };


//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        vector<int> res = obj.diagonalSum(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 1;
}
// } Driver Code Ends