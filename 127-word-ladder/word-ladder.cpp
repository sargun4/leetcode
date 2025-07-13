//TC-O(N*wordlen*26)
//SC-O(N)
// q stores the current word & no of transformation steps taken so far.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;//{word,steps}
        q.push({beginWord,1});//insert the beginword in the q with 1-1st transformation.
        unordered_set<string> set(wordList.begin(),wordList.end());//add all words to set
        set.erase(beginWord);//mark the startWord as visited by removing it frm set

        while(!q.empty()){
            auto curr=q.front(); q.pop();
            string word=curr.first;
            int steps=curr.second;
            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){//for all chars in word
                int originalChar=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;//replace the char with all 26 chars
                    if(set.find(word)!=set.end()){//if it exists in set
                        set.erase(word);//mark it as vis- remove frm set
                        q.push({word,steps+1});//
                    }
                }
                word[i]=originalChar;//restore original char
            }
        }
        return 0;
    }
};
