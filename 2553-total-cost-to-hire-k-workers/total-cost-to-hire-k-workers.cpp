class Solution {
public:
    // typedef pair<int,int> pii;
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        //minheap for first candidate(int) workers
        priority_queue<int,vector<int>,greater<>> pq1;
        //minheap for last candidate(int) workers
        priority_queue<int,vector<int>,greater<>> pq2;
        int hired=0;
        long long cost=0;
        int i=0; int j=n-1;

        while(hired<k){//k sessions
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i]);
                i++;//move to next idx
            }
            while(pq2.size()<candidates && j>=i){
                pq2.push(costs[j]);
                j--;//moving frm last idx to no of candidates
            }
            //if pq1 has no elmnts , set min_pq1 to inf
            int min_pq1= pq1.size()>0 ? pq1.top():INT_MAX;
            //if pq2 has no elmnts , set min_pq2 to inf
            int min_pq2= pq2.size()>0 ? pq2.top():INT_MAX;

            if(min_pq1<=min_pq2){//in case of tie,lower idx elmnt will be in pq1
                cost+=min_pq1;
                pq1.pop();
            }else{//
                cost+=min_pq2;
                pq2.pop();
            }
            hired++;
        }
        return cost;
    }
};