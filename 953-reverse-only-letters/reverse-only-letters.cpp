class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> letters;//lifo
        // Pu]sh all letters into stack
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                letters.push(s[i]);
            }
        }
        // Replace letters in the string with those from the stack

        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                s[i] = letters.top();
                letters.pop();
            }
        }
        return s;
    }
};