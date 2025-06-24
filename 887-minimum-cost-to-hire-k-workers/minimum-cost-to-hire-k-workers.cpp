class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double,int>> wageToQualityRatio;//{ratio,quality}
        for(int i=0;i<n;i++){
            double ratio = (double)wage[i] / quality[i] ;
            wageToQualityRatio.push_back({ratio, quality[i]});
        }
        sort(begin(wageToQualityRatio),end(wageToQualityRatio));

        double sum_quality=0;
        double mincost=DBL_MAX;
        //max-heap to keep track of top k smallest qualities
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            double ratio=wageToQualityRatio[i].first;
            int quality=wageToQualityRatio[i].second;

            pq.push(quality);
            sum_quality+=quality;
            //if more than k workers,remove highest quality one
            if(pq.size()>k){
                sum_quality-=pq.top();
                pq.pop();
            }
            // if exactly k,get totalcost which is min
            if(pq.size()==k){
                mincost=min(mincost,sum_quality*wageToQualityRatio[i].first);
            }
        }
        return mincost;
    }
};