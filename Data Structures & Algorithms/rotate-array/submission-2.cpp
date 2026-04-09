class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k%n==0) return;
        k=k%n;
        // moving k step right means, bringing last k elements to the front
        reverse(nums.begin(),nums.end()); // now the last k elements are at the front but in reverse order
        reverse(nums.begin(),nums.begin()+k); // we first reverse the first k elements
        reverse(nums.begin()+k,nums.end()); // then reverse the remaining
    }
};