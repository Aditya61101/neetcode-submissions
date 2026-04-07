// inplace swapping
class Solution {
private:
    void solve(int s, vector<int>&n, vector<vector<int>>&r) {
        if(s==n.size()) {
            r.push_back(n); return;
        }
        for(int i=s;i<n.size();i++) {
            swap(n[s], n[i]);
            solve(s+1, n, r);
            // undo the swap so that we retain original position for next recursion branch
            swap(n[s], n[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        solve(0, nums, res);
        return res;
    }
};
