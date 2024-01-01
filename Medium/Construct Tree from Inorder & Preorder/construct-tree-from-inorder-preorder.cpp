//{ Driver Code Starts
//

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

class Solution{
    public:
    void createMapping(int in[], map<int,vector<int>> &nodeToindex, int n){
        for(int i=0;i<n;i++){
            nodeToindex[in[i]].push_back(i);
        }
    } 
    Node *solve(int in[],int pre[], int &index,int inorderStart,int inorderEnd,int n,map<int,vector<int>>&nodeToindex){
        if(index>=n || inorderStart>inorderEnd){
            return nullptr;
        }
        int element = pre[index++];
        Node *root = new Node(element);
        vector<int> pos = nodeToindex[element];
        int i;
        for(i=0;i<pos.size();i++){
            if(pos[i]>=inorderStart && pos[i]<=inorderEnd){
                break;
            }
        }
        root->left =solve(in,pre,index,inorderStart,pos[i]-1,n,nodeToindex);
        root->right =solve(in,pre,index,pos[i]+1,inorderEnd,n,nodeToindex);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n){
        int preindex=0;
        map<int,vector<int>>nodeToindex;
        createMapping(in,nodeToindex,n);
        Node *ans =solve(in,pre,preindex,0,n-1,n,nodeToindex);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends