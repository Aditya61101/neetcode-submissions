class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int len=0;
        for(int x:st) {
            // To avoid repeatedly recounting the same sequences, 
            // we only want to start counting 
            // when we find the beginning of a consecutive sequence.
            if(!st.count(x-1)) {
                int y=x+1;
                while(st.count(y)) y++;
                len=max(len,y-x);
            }
        }
        return len;
    }
};
