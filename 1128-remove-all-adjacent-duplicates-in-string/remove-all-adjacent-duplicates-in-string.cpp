class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        vector<char> st(n);
        int i = 0;  
        for(int j = 0; j < n; j++) {
            char currchar = s[j];
            if(i>0 && st[i-1] == currchar) { // If curr char is same as last char in stack
                i--; //pop last char from stack
            } else {
                st[i]=currchar; // Push curr char to stack
                i++;
            }
        } 

        string res = "";
        for(int k = 0; k < i; k++) {
            res += st[k];
        } 
        return res;
    }
};
