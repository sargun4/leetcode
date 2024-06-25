//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
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
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends
 
bool solve(Node* root,int &ctr,int &node,int &val){
    if(root==NULL) return 0;
    if(root->data==node){
        return 1;
    }
    int l=solve(root->left,ctr,node,val);
    int r=solve(root->right,ctr,node,val);
    if(l||r){
        ctr--;
        if(ctr==0) val=root->data;
        
        return 1;
    }
    return 0;   
}
int kthAncestor(Node *root, int k, int node){   
    int ctr=k;
    int val=-1;
    solve(root,ctr,node,val);
    return val;
}

// 'ctr' to track of ancestors encountered and 'val' to store final kth ancestor value.

// We'll update 'val' only when 'ctr' becomes 0 because that will tell us that we are
//  currently on the kth ancestor.
//  Also , 'ctr' will only be updated once we find node with the given value as we'll be returning 1, else 0.

// Here, 'ctr' is passed by reference to keep track of ancestors encountered and we don't want to 
// lose it when coming back from recusive calls. 
// Also 'val' is passed by reference to store the value of kth ancestor value if found , and we don't want to lose it in recursive calls.

// Traversal would be simply ' Preorder ' with slight variation.