//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;      
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}

}

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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*The node structure
struct Node {
int data;
Node * right, * left;
};*/

class Solution{
  public:
    /*The function should return the root of the modified tree*/
    // 1) Agr root NULL ho gya toh bhyi simply return NULL;
    // 2) Agr root ki val exactly equal hai k toh iska mtlb iske left main jitni
    // bhi values hongi woh k se km hongi, toh return root -> left.
    // 3) Agr root ka data k se bda hai toh yeh toh pkka hai ki right main bhi sb values
    // k se bdi hongi toh hme right main toh jana nhi, hm phir root ke left main jayenge
    // aur khojenge ki aisi konsi jagah se root ki value less than k milti hai, toh isiliye
    // return deleteNode(root -> left, k);
    // 4) Agr root ka data k se km hai toh yeh toh sure hai ki iske left main jitni bhi 
    // values hongi woh sb k se km hongi toh unhe toh delete nhi krna hai. Since root ka
    // data k se km hai toh iske right main yeh possibility ho skti hai ki koi value 
    // k se bdi ho, toh hme usse delete krna hoga, so go into the right, i.e
    // deleteNode(root -> right, k);
    
    Node* deleteNode(Node* root, int k){
    if(root == NULL){ // If root is NULL, return NULL{
        return NULL;
    }
    if(root -> data == k){ // If root's data is equal to k, return its left child
        return (root -> left);
    }
    if(root -> data > k){ // If root's data is greater than k, recursively delete in the left subtree
        return deleteNode(root -> left, k);
    }
    if(root -> data < k){ // If root's data is less than k, recursively delete in the right subtree
        root -> right = deleteNode(root -> right, k);
    }
    return root; // Return the modified root
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    getchar();
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        string s;
        getline(cin,s);
        
        root = buildTree(s);
        int k;
        cin>>k;
        getchar();
        Solution obj;
    Node *R= obj.deleteNode(root,k);
    	inorder(R);
      cout<<endl;
    }
}



// } Driver Code Ends