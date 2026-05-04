class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int pn=0, pn_1=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            int curr=max(pn_1,nums[i]+pn);
            pn=pn_1;
            pn_1=curr;
        }
        return pn_1;
    }
};
