class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=1;
        int n = nums.size();
        int cnt=1;
        for(int k=1;k<n;k++) {
            if(nums[k]==nums[k-1]) continue;
            cnt+=1;
        }
        
        bool hasset=false;
        while(j<n) {
            if(!hasset && nums[j]==nums[j-1]) {
                i=j;
                hasset=true;
            }
            else if(nums[j]!=nums[j-1]) {
                nums[i]=nums[j];
                i+=1;
            }
            j++;
        }
        // for(int k=0;k<n;k++) {
        //     cout<<nums[k]<<" ";
        // }
        
        return cnt;
    }
};