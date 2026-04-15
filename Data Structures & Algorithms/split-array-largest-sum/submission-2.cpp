class Solution {
    int n;
    vector<int>prefix;
    bool canSplit(int largest, int k) {
        int i=0, subarrays=0;
        while(i<n){
            int l=i+1, r=n;
            while(l<=r) {
                int m = l+(r-l)/2;
                if(prefix[m]-prefix[i]<=largest) l=m+1;
                else r=m-1;
            }
            i=r;
            subarrays++;
            if(subarrays>k) return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        n = nums.size();
        prefix.resize(n+1, 0);
        int l = 0;
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
            l = max(l,nums[i]);
        }
        int r = prefix[n];
        while(l<r) {
            int m = l+(r-l)/2;
            if(canSplit(m, k)) {
                r=m;
            } else l=m+1;
        }
        return l;
    }
};