using p=pair<int,int>;
class Solution {
public:
    int Manhattan(int n1,int n2){
        return abs(n1-n2);
    }
    struct compare{
        bool operator()(const p& p1, const p& p2) {
            if (p1.second != p2.second) {
                return p1.second < p2.second; // max-heap based on distance
            }
            return p1.first > p2.first; // if distances are same, prefer smaller element
        }
    };
    vector<int> printKClosest(vector<int> arr, int k, int x){
        int n=arr.size();
        priority_queue<p, vector<p>, compare> pq;//maxheap-{num,dist}
        for(int i=0;i<n;i++){
            int dist=Manhattan(arr[i],x);
            pq.push({arr[i],dist});
            if(pq.size()>k){
                pq.pop();// remove farthest if size exceeds k
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            auto curr=pq.top(); pq.pop();
            int num=curr.first;
            ans.push_back(num);
        }
        reverse(ans.begin(),ans.end());//get closest first
        return ans;
    }
};