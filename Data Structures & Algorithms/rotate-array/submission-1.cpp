class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k%n==0) return;
        k=k%n;
        reverse(nums.begin()+n-k,nums.end());
        reverse(nums.begin(),nums.end());
        reverse(nums.begin()+k,nums.end());
    }
};