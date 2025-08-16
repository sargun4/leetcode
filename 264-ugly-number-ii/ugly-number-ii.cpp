//T-O(nlogm)
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>> pq;//minheap
        unordered_set<long> seen;//nos alr seen in set
        pq.push(1); //1st ugly no = 1
        vector<int> primeFactors={2,3,5};
        seen.insert(1);
        long currUgly=1;
        for(int i=0;i<n;i++){
            currUgly=pq.top(); 
            pq.pop();
            for(int prime:primeFactors){
                long nextUgly=currUgly*prime;
                if(seen.find(nextUgly)==seen.end()){//not yet in set
                    pq.push(nextUgly);
                    seen.insert(nextUgly);
                }
            }
        }
        return currUgly;
    }
};