class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        char maxdig='\0';
        for(int i=0;i<n-2;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                maxdig=max(maxdig,num[i]);
            }
        }
        // If maxdig is NULL return empty string, 
        // otherwise string of size 3 with maxdig chars.
        return maxdig=='\0' ? "":string(3,maxdig);
    }
};