class Solution {
private:
    void solve(int s, vector<int>&n, vector<vector<int>>&r, vector<int>&sub) {
        r.push_back(sub);
        for(int i=s;i<n.size();i++) {
            if(i>s && n[i]==n[i-1]) continue;
            sub.push_back(n[i]);
            solve(i+1, n, r, sub);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // ranges::sort(nums);
        sort(nums.begin(), nums.end());
        vector<vector<int>>r; vector<int>sub;
        solve(0, nums, r, sub);
        return r;
    }
};
