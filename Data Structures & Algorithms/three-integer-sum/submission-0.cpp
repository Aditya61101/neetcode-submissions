class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++) {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int l=i+1, r=n-1;
            int tar = -1*nums[i];
            while(l<r) {
                int sum = nums[l]+nums[r];
                if(sum>tar) r-=1;
                else if(sum<tar) l+=1;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l]==nums[l+1]) l+=1;
                    while(l<r && nums[r]==nums[r-1]) r-=1;
                    l+=1; r-=1;
                }
            }
        }
        return ans;
    }
};
