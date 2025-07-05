class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int &num:nums){
            map[num]++;
        }
        //minheap to get the min freq elmnts at top so they can b del if size of pq exceeds k
        priority_queue<pii,vector<pii>,greater<>> pq;//{freq:elmnt}
        //push elmnts in minheap
        for(auto it:map){//O(n)
            int elmnt=it.first; 
            int freq=it.second;
            pq.push({freq,elmnt});
            if(pq.size()>k){//only top k elmnts needed-so pop when size exceeds k-O(logk)
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            int val=pq.top().second;
            res.push_back(val);
            pq.pop();
        }
        return res;
    }
};


// // O(n) 
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> map;
//         int topfreq=0;
//         for(int x: nums) {
//             map[x]++;
//             topfreq = max(topfreq, map[x]);
//         }

//         vector<int> ans;

//         unordered_map<int, vector<int>> freqmap;
//         for(auto it: map) {
//             freqmap[it.second].push_back(it.first);
//         }

//         int ctr=0;
//         while(ctr<k) {
//             if(freqmap.find(topfreq) != freqmap.end()) {
//                 vector<int> v = freqmap[topfreq];
//                 int n = v.size();
//                 for(int i=0; i<n; i++) {
//                     ans.push_back(v[i]);
//                     ctr++;
//                     if(ctr == k)
//                         break;
//                 }
//             }
//             topfreq--;
//         }

//         return ans;
//     }
// };