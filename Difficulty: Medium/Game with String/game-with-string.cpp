class Solution {
  public:
    int minValue(string &s, int k) {
        int n=s.size();
        unordered_map<char,int> freqMap;//{char:freq}
        for(int i=0;i<n;i++){
            freqMap[s[i]]++;
        }
        priority_queue<int> pq;
        for(auto it:freqMap){
            int freq=it.second;
            pq.push(freq);
        }
        while(k-- >0 && !pq.empty()){
            int freq=pq.top(); pq.pop();
            freq--;
            if(freq>0){
                pq.push(freq);
            }
        }
        int ans=0;
        while(!pq.empty()){
            int ctr=pq.top(); pq.pop();
            ans+=ctr*ctr;
        }
        return ans;
    }
};