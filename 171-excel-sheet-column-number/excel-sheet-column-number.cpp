class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.size();
        int ans=0;
        // for(int i=n-1;i>=0;i--){
        //     ans+=(columnTitle[i]-'A'+1)*pow(26,n-i-1);
        // }
        for(char c:columnTitle){
            ans=ans*26+(c-'A'+1);
        }
        return ans;
    }
}; 