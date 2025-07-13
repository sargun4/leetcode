//TC-O(N*wordlen*26)
//SC-O()
#include<bits/stdc++.h>
using namespace std;
// q stores the current word & no of transformation steps taken so far.
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>> q; //{word,steps}
        q.push({startWord, 1});
        unordered_set<string> set(wordList.begin(),wordList.end());//add all words to set
        set.erase(startWord);//mark the startWord as visited by removing it frm set
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second; 
            q.pop();
            if(word==targetWord) return steps;
            for(int i=0;i<word.size();i++){// for all chars in word
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;//replace the char with all 26 chars
                    if(set.find(word)!=set.end()){//if it exists in set
                        set.erase(word);//mark it as vis- remove frm set
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;//restore original char
            }
        }
        return 0;
    }
};

