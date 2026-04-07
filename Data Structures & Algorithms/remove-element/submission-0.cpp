class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int n = nums.size();
        for(int num:nums) if(num==val) cnt+=1;

        int i=0, j=n-1;
        while(i<j) {
            while(i<j && nums[j]==val) j-=1;
            if(i>=j) break;
            if(nums[i]==val) {
                swap(nums[i], nums[j]);
                // j-=1;
            }
            i+=1;
        }
        return n-cnt;
    }
};