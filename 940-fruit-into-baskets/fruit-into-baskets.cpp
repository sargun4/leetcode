class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> map; //{num:freq} in sliding window
        int i=0; int j=0;
        int ctr=0;
        while(j<n){ 
            map[fruits[j]]++; //incr freq of that fruit
            if(map.size()<=2){//valid window
                ctr=max(ctr,j-i+1);
            }else{//more than 2 fruit types are now here
                map[fruits[i]]--;//so remove that fruit
                if(map[fruits[i]]==0){//if its completely gone
                    map.erase(fruits[i]);//remove that entry
                }
                i++;// move to next
            }
            j++;
        }
        return ctr;
    }
};