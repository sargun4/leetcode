//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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

vector<int> Kdistance(struct Node *root, int k);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k;
		scanf("%d ",&k);
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = Kdistance(root, k);
        for(int i = 0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    return 1;
}
// } Driver Code Ends


 

// function should print the nodes at k distance from root
vector<int> Kdistance(struct Node*root, int k){
    vector<int> ans;
    if(root==NULL) return ans;
    queue<Node*> q;
    q.push(root);
    int currlvl=0;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* node=q.front();
            q.pop();
            if(currlvl==k){
                ans.push_back(node->data);
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        currlvl++;
    }
    // cout<<currlvl;
    if(k>currlvl) return {};
    return ans;
}