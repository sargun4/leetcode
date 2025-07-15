class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> prefixMax(begin(arr),end(arr));//prefixMax[i] = max in arr[0..i]
        vector<int> suffixMin(begin(arr),end(arr));//suffixMin[i] = min in arr[i..n-1]
        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i],prefixMax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suffixMin[i]=min(suffixMin[i],suffixMin[i+1]);
        }
        int ctr=0;//chunks ctr
        for(int i=0;i<n;i++){
            int prevMax=i>0 ? prefixMax[i-1]:-1;//max in left part
            int nextMin=suffixMin[i];//min in right part
            if(prevMax<nextMin){
                ctr++;//make chunk
            }
        }
        return ctr;
    }
};