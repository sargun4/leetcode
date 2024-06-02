class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        int low=0,high=k-1;
        while(low<n){
            int start=low;
            if(high>=n)
                high=n-1;
            while(low<=high){
                swap(s[low],s[high]);
                low++;
                high--;
            }
            low = start + 2*k;
            high = low + k-1;
        }
        return s;
        
    }
};