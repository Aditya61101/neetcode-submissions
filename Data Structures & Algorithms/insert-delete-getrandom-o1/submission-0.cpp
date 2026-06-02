class RandomizedSet {
    vector<int>set;
    unordered_map<int,int>valIndexMap;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(valIndexMap.count(val)) return false;

        set.push_back(val);
        valIndexMap[val]=(int)set.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!valIndexMap.count(val)) return false;
        
        int idx = valIndexMap[val];
        
        int lastValue = set[set.size()-1];
        int lastIdx = valIndexMap[lastValue];
        
        valIndexMap[lastValue]=idx;
        valIndexMap.erase(val);

        swap(set[idx],set[lastIdx]);
        set.pop_back();

        return true;
    }
    
    int getRandom() {
        int n=set.size();
        return set[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */