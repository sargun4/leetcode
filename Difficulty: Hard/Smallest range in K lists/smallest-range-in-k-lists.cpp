// Initialize a min-heap and push the first element of each list into it.
// Keep track of the current maximum element in the heap.
// Calculate the current range (maxe - min_heap.top()) and update the answer if a smaller range is found.
// Move the pointer of the list that contributed the smallest element and
//push the next element into the heap.
// Repeat until one of the lists is exhausted
typedef pair<int,pair<int,int>> p; // {value, {row, col}}
class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int n=arr.size();//no of rows/lists
        
        int currmax=INT_MIN;
        priority_queue<p,vector<p>,greater<p>> pq;//minheap-{val,{i,j}}
        //push 1st elmnt of each list into heap
        for(int i=0;i<n;i++){
            pq.push({arr[i][0],{i,0}});
            currmax=max(currmax,arr[i][0]);
        }
        vector<int>ans={pq.top().first,currmax}; //store res range-[start,end]
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int currmin=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;
            //check if curr range < prev
            if(currmax-currmin < ans[1]-ans[0]){
                ans[0]=currmin;
                ans[1]=currmax;
            }
            //if reached end of list, break(since we cant extend further)
            if(j+1==arr[i].size()){
                break;
            }else{//push nxt elmnt frm same elmnt into pq
                int next_elmnt=arr[i][j+1];
                pq.push({next_elmnt,{i,j+1}});//at most n*k elmnts pushed into pq
                //T-O(n*k*logk)
                currmax=max(currmax,next_elmnt);
            }
        }
        return ans;
    }
};