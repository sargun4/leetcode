//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector <int> &v)
{
    sort( v.begin() , v.end() );
    for( int i=0 ; i<v.size() ; i++ )
        cout<< v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;
    
    q.push(root);
    
    Node* next_row = NULL;
    
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        
        if(n==next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }
        
        v.push_back(n->data);
        
        if(n->left)
        {
            q.push(n->left);
            if(next_row == NULL) next_row = n->left;
        }
        
        if(n->right)
        {
            q.push(n->right);
            if(next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/


// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

//  Step 1:
//  create an array of Nodes arr having value at nodes from 0 to N-1 
// since we know from the q that the indices of parent array represent values of nodes and the value of 
// parent array represents the parent Node having this value of the Node having value equal to the index. 

// step 2: 
// Now we have an array of Nodes of tree. so we will traverse the parent array and will check if parent[i] = -1 then 
// arr[i]=root of tree. if arr[parent[i]]->left or arr[parent[i]]->right is NULL then make arr[parent[i]]->left
//  or arr[parent[i]]->right = arr[i] accordingly .

// step 3: Now return the root of tree.
class Solution{
  public:
  
 Node *createTree(int parent[], int N){
    Node *arr[N]; //store nodes
    Node *root;
    for(int i=0;i<N;i++){
        arr[i] = new Node(i);
    }
    for(int i=0;i<N;i++){
        if(parent[i]==-1){
            root = arr[i];
        }
        else{
            if(arr[parent[i]]->left==NULL)
                arr[parent[i]]->left = arr[i];
            else if(arr[parent[i]]->right==NULL)
                arr[parent[i]]->right = arr[i];
        }
    }
    return root;  
}
  
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for( int i=0 ; i<n ; i++ )
            cin>> a[i];
            
        Solution ob;
        
        Node *res = ob.createTree(a,n);
        
        printLevelOrder(res);
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends