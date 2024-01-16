#include <bits/stdc++.h>
using namespace std;
class RandomizedSet {
public:
    //Initialize data structures here.
    unordered_map<int, int> idxMap; // key - value , value - index
    vector<int> nums; 	// store the numbers in order of insertion

    RandomizedSet() {
        // not initializing the map here because it will be done in add and remove methods.
    }
    
    bool insert(int val) {
        if(idxMap.find(val)!=idxMap.end()) return false;//if elmnt already present, then false
        nums.push_back(val);
        idxMap[val]=nums.size()-1; //map the value to its
        return true;
    }
    
    bool remove(int val) {
        if(idxMap.find(val)==idxMap.end()) return false;
        int last=nums.back();
        idxMap[last]=idxMap[val];
        nums[idxMap[last]]=last;
        nums.pop_back();
        idxMap.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */