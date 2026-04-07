class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using pii = pair<int,int>;
            
                unordered_map<int,int>ump;
                    for(int num:nums) ump[num]++;
                        
                            priority_queue<pii, vector<pii>, greater<pii>>pq;
                                for(auto &it:ump) {
                                        pq.emplace(it.second, it.first);
                                                if(pq.size() > k) pq.pop();
                                                    }

                                                        vector<int>ans;
                                                            while(pq.size()) {
                                                                    ans.push_back(pq.top().second);
                                                                            pq.pop();
                                                                                }
                                                                                    return ans;
    }
};
