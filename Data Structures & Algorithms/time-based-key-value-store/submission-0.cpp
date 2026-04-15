class TimeMap {
public:
    // key -> [{value1,timestamp1}, {value2, timestamp2}...]
    unordered_map<string,vector<pair<string,int>>>store;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!store.count(key)) return "";
        vector<pair<string,int>>values = store[key];
        int l=0, r=values.size()-1;
        int idx = -1;
        while(l<=r) {
            int m = l+(r-l)/2;
            if(values[m].second<=timestamp) {
                idx=m; l=m+1;
            } else r=m-1;
        }
        if(idx==-1) return "";
        return values[idx].first;
    }
};
