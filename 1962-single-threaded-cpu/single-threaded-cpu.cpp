#define pii pair<int,int>
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<int,3>> sortedTasks;
        for(int i=0;i<n;i++){
            int start_time=tasks[i][0];
            int processing_time=tasks[i][1];
            sortedTasks.push_back({start_time,processing_time,i});
        }
        //sort
        sort(begin(sortedTasks),end(sortedTasks));
        vector<int> ans;
        int idx=0;
        long long currtime=0;
        //minheap
        priority_queue<pii,vector<pii>,greater<>> pq;//{processngtime,idx}
        while(idx<n || !pq.empty() ){//
        //when we are starting out, pq is empty and currtime is set as the earlist tasks' start time
            if(pq.empty() && currtime<sortedTasks[idx][0]){
                currtime=sortedTasks[idx][0];
            }
            while(idx<n && sortedTasks[idx][0]<=currtime){
                pq.push({sortedTasks[idx][1],sortedTasks[idx][2]});//{processngtime,idx}
                idx++;
            }
            pii currtask=pq.top(); pq.pop();
            currtime+=currtask.first;//processing time for curr task added
            ans.push_back(currtask.second);//idx
        }
        return ans;
    }
};