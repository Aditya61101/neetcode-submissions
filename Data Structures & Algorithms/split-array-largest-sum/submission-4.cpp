class Solution {
    int n;
    vector<int>prefix;
    bool canSplit(int largest, int k) {
        int i=0, subarrays=0;
        while(i<n){
            // searching for the end of current subarray
            int l=i+1, r=n;
            // stores end of the current subarray
            int res=i;
            while(l<=r) {
                int m = l+(r-l)/2;
                int sum = prefix[m] - (i==0 ? 0:prefix[i-1]);
                if(sum<=largest) {res=m; l=m+1;}
                else r=m-1;
            }
            // res is at the end of the current subarray,
            // the start of new subarray is res+1
            i=res+1;
            subarrays++;
            if(subarrays>k) return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        n = nums.size();
        prefix.resize(n, 0);
        prefix[0]=nums[0];
        int l = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + nums[i];
            l = max(l,nums[i]);
        }
        int r = prefix[n-1];
        // T.C -> O(log(sum))
        while(l<r) {
            int m = l+(r-l)/2;
            // T.C of canSplit -> k*logn
            if(canSplit(m, k)) {
                r=m;
            } else l=m+1;
        }
        return l;
    }
};

// T.C: O(n)+O(log(sum) * (k * logn))
// S.C: O(n)