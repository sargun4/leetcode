class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // int n=difficulty.size();
        int n=worker.size();
        priority_queue<pair<int,int>> pq; //max heap
        for(int i=0;i<n;i++){
            int diff=difficulty[i];
            int prof=profit[i];
            pq.push({prof,diff});
        }
        sort(begin(worker),end(worker),greater<int>()); //sort on desc
        int i=0;
        int totalprof=0;
        while(i<n && !pq.empty()){
            if(pq.top().second>worker[i]){
                pq.pop();
            }else{
                totalprof+=pq.top().first;
                i++;
            }
        }
        return totalprof;
    }
};