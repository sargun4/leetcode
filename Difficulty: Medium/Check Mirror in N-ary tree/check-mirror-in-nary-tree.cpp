// User function Template for C++

class Solution {
  public:
int checkMirrorTree(int n, int e, int A[], int B[]) {
        //unordered map to store edges for each node in tree A
        unordered_map<int,stack<int>>mp;
        for(int i=0;i<2*e;i+=2){//store edges of treeA in map
            mp[A[i]].push(A[i+1]);
        }
        
        for(int i=0;i<2*e;i+=2){
//if top elmnt of stack for B[i] is not equal to B[i+1], they r not mirrors
            if(mp[B[i]].top()!=B[i+1]) return 0;//false
            mp[B[i]].pop();//remove top elmnt frm stack for B[i]
        }
        return 1;//true
    }
};