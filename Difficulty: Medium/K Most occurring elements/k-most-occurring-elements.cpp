// Function to print the k numbers with most occurrences

using p=pair<int,int>;
class Solution {
  public:
    // Function to return the sum of frequencies of k numbers
    // with most occurrences in an array.
    
    int kMostFrequent(vector<int>& arr, int k) {
        unordered_map<int,int> map;//{elmnt:freq}
        for(auto &it:arr){
            map[it]++;
        }
        //{freq,elmnt}
        priority_queue<p,vector<p>,greater<>> pq;//minheap-since we want max freq
        for(auto &it:map){
            int elmnt=it.first; int freq=it.second;
            pq.push({freq,elmnt});
            if(pq.size()>k){
                pq.pop();
            }
        }
        int sum=0;
        while(!pq.empty()){
            int freq=pq.top().first;
            sum+=freq;
            pq.pop();
        }
        return sum;
    }
};