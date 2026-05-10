class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        using pii = pair<int,int>;
        
        vector<vector<int>>sortedTrips;
        for(auto trip:trips) {
            // {from,to,passengers}
            sortedTrips.push_back({trip[1],trip[2],trip[0]});
        }
        sort(sortedTrips.begin(),sortedTrips.end());
        // {to,passengers}
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        
        int passengers=0;
        for(auto trip:sortedTrips) {
            // if next trip pickup excceds any current shortest trips' drop location
            while(pq.size() && trip[0]>=pq.top().first) {
                // unboard the passengers
                passengers-=pq.top().second;
                pq.pop();
            }
            passengers+=trip[2];
            // if passengers that are travelling right now becomes greater than
            // capacity of the vehicle
            if(passengers>capacity) return false;
            pq.emplace(trip[1],trip[2]);
        }
        return true;
    }
};