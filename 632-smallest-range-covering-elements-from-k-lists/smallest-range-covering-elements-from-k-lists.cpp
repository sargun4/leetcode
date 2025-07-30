using p=pair<int,pair<int,int>>; //{val,{row,col}}
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();//no of rows/lists
        priority_queue<p,vector<p>,greater<p>> pq;//minheap
        int currmax=INT_MIN;
        for(int i=0;i<n;i++){
            pq.push({nums[i][0],{i,0}});
            currmax=max(currmax,nums[i][0]);
        } 
        vector<int> ans={pq.top().first,currmax};
        while(pq.size() == nums.size()){
            auto curr=pq.top(); pq.pop();
            int currmin=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;
            //if curr range < prev range, update
            if(currmax-currmin < ans[1]-ans[0]){
               ans[0]=currmin;
               ans[1]=currmax;
            }
            //if reached end of list, break(since we cant extend further)
            if(j+1==nums[i].size()){
                break;
            }else{//push nxt elmnt frm same elmnt into pq
                int next_elmnt=nums[i][j+1];
                pq.push({next_elmnt,{i,j+1}});//at most n*k elmnts pushed into pq
                //T-O(n*k*logk)
                currmax=max(currmax,next_elmnt);
            }
        }
        return ans;
    }
};