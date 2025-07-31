class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>prev;
        unordered_set<int> curr;
        unordered_set<int> res;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(const int&x:prev){
                curr.insert(x|arr[i]);
                res.insert(x|arr[i]);
            }
            curr.insert(arr[i]);
            res.insert(arr[i]);
            prev=curr;
            curr.clear(
            );
        }
        return res.size();
    }
};