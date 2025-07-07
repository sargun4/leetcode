class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(begin(events),end(events));
        //minheap
        priority_queue<int,vector<int>,greater<int>> pq;

        int day=events[0][0];//start
        int i=0;//ptr to iter on events
        int ctr=0;//res no of events attended
        while(!pq.empty()|| i<n){//
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);//end day
                i++;
            }
            if(!pq.empty()){
                pq.pop();//1 event attended on this day
                ctr++;
            }
            day++;
            //skip those events whose endday<day;
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
        }
        return ctr;
    }
};