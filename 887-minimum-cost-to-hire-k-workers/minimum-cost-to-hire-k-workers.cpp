class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        double res=DBL_MAX;
        vector<pair<double,int>> worker_ratio(n);

        for(int worker=0; worker<n; worker++){
            worker_ratio[worker] = make_pair((double)wage[worker]/quality[worker],quality[worker]);
        }
        sort(begin(worker_ratio), end(worker_ratio));

        int sumquality = 0;
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<k;i++){
            pq.push(worker_ratio[i].second);
            sumquality+=worker_ratio[i].second;
        }
        double managerRatio=worker_ratio[k-1].first;
        res=managerRatio*sumquality;
        for(int manager=k; manager<n; manager++){
            double managerRatio=worker_ratio[manager].first;
            pq.push(worker_ratio[manager].second);
            sumquality+=worker_ratio[manager].second;
            if(pq.size()>k){
                sumquality-=pq.top();
                pq.pop();
            }
            res=min(res,managerRatio*sumquality);
        }
        return res;
    }
};