class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        freq[0]=1;
        int cnt=0,sum=0;
        for(int x:nums){
            sum+=x;
            if(freq.count(sum-k)){
                cnt+=freq[sum-k];
            }
            freq[sum]+=1;
        }
        return cnt;
    }
};