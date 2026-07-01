#define pis pair<int, string>
class TimeMap {
    unordered_map<string, vector<pis>> keyVal;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyVal[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        const vector<pis>& vals = keyVal[key];
        int l = 0, r = vals.size() - 1;
        int ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (vals[m].first <= timestamp) {
                ans = m;
                l = m + 1;
            } else
                r = m - 1;
        }
        return ans == -1 ? "" : vals[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
