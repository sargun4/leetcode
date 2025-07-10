// we want the decreasing order for the frequency of the strings and increasing order in the lexiographical way so that the strings with the least frequency and cannot be fitted inside k can be poped.
// So, p1.first > p2.first will return true only when the frequency of first string is more than the second
// similary, p1.second < p2.second will return true when the string s1 in p1 is lexiographically smaller then string s2 in p2.

class Solution {
public:
    typedef pair<string,int> p;
    struct compare{
        bool operator()(p& p1,p& p2){//p1-lower,p2-higher
            if(p1.second==p2.second) return p1.first < p2.first;//if freq are same, lower lexi - more priority
            return p1.second > p2.second;//lower freq=lower priority
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int> map;
        for(auto &it:words){
            map[it]++;
        }
        priority_queue<p,vector<p>,compare> pq;//minheap-{char,freq}
        for(auto it:map){
            pq.push({it.first,it.second});
            if(pq.size()>k){
                pq.pop();// pop least frequent or worst lexicographically
            }
        }
    // Since it’s a min-heap, the least frequent of the top-K comes out first.
    // We insert into result from end to start so that most frequent ends up at the front.
        vector<string> ans(k);
        for(int i=k-1;i >= 0;i--) {
            ans[i] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};