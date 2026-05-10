class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>locations(1001);
        for(auto trip:trips) {
            int from=trip[1], to=trip[2], passengers=trip[0];
            locations[from]+=passengers;
            locations[to]-=passengers;
        }
        int passengers=0;
        for(int pass:locations) {
            passengers+=pass;
            if(passengers>capacity) return false;
        }
        return true;
    }
};