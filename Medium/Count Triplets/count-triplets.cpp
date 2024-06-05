//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends

int countTriplets(struct Node* head, int x) {
    int ans = 0;//count of tripletes
    bool vis[10001];
    memset(vis,false,sizeof(vis));
    while(head){
        Node* node = head->next;
        while(node){
            int target=x-(node->data)-(head->data);
            if(vis[max(0,target)]==true)
                ans++;
            node = node->next;
        }
        vis[(head->data)] = 1;
        head = head->next;
    }
    return ans;
} 