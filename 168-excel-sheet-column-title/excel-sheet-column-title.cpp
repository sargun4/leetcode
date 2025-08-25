class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber){
            columnNumber--;
//get remaind when dividing by 26 to get the curr char(0:A,...,Z:25)
            int rem=columnNumber%26;
            ans.push_back('A'+rem);
            columnNumber/=26;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};