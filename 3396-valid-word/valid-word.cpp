class Solution {
public:
    bool isValid(string word) {
        bool hasVowel=false;
        bool hasConsonant=false;
        int n=word.size();
        if(n<3) return false;

        for(char ch:word){
            if(isalpha(ch)){
                ch=tolower(ch);
                if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                    hasVowel=true;
                }else{
                    hasConsonant=true;
                }
            }else if(!isdigit(ch)){
                return false;
            }
        }
        return hasVowel && hasConsonant;
    }
};