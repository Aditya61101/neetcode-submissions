class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans; // stores max value of each window
        deque<int>dq; // stores indexes such that the values at those indexes are in decreasing order
        int i=0, n=nums.size();
        for(int j=0;j<n;j++) {
            while(dq.size() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            if(j-i+1>k) {
                if(dq.size() && dq.front()==i) dq.pop_front();
                i++;
            }
            if(j-i+1==k) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
