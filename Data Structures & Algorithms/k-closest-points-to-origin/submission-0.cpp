class Solution {
    double getDistance(vector<int>&pt) {
        return (double)sqrt(pt[0]*(double)pt[0]+pt[1]*(double)pt[1]);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // a max heap works, since a max heap of k size
        // stores k points closest to origin
        // in a way that the bottom in that heap is the closest 
        // whereas top is the kth closest.
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<points.size();i++) {
            double dist = getDistance(points[i]);
            pq.emplace(dist,i);
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>>closests;
        while(pq.size()) {
            closests.push_back(points[pq.top().second]);
            pq.pop();
        }
        return closests;
    }
};
