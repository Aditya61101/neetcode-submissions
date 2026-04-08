class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++) {
                if(j-1!=i && nums[j]==nums[j-1]) continue;
                int l = j+1, r=n-1;
                while(l<r) {
                    long long sum = (long long)nums[i]+(long long)nums[j]+(long long)nums[l]+(long long)nums[r];
                    if(sum>target) {
                        r-=1;
                    } else if(sum<target) {
                        l+=1;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l+=1; r-=1;
                        while(l<r && nums[l]==nums[l-1]) l+=1;
                    }
                }
            }
        }
        return ans;
    }
};
// T.C: O(n*logn+n^3) ~ O(n^3)
// S.C: O(1)