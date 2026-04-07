class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cad=nums[0], cnt=1;
        for(int i=1;i<n;i++) {
            if(cnt==0 || cad==nums[i]) {cad=nums[i]; cnt+=1;}
            // else if() cnt+=1;
            else cnt-=1;
        }
        return cad;
     }
};