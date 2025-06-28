class Solution {
public:
    int maxSubstrings(string word) {
        int n=word.length();
        int ans=0;
        vector<int> arr(26, -1);//store last seen idx of char
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            //if char has been seen before-
            if(arr[idx]!=-1 && i-arr[idx]+1>=4){
                ans++;//valid substr of len>=4 ending at i;
                for(int j=0;j<26;j++){//reset arr since substrs shd be nonoverlpping
                    arr[j]=-1;
                }
            }else{
                if(arr[idx]==-1){//1st time seeing this char in curr substr
                    arr[idx]=i;//mark idx 1st seen
                }
            }
        }
        return ans;
    }
};