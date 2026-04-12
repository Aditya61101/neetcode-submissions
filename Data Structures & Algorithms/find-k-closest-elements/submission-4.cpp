class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l=0, r=n-k;
        // O(log(n-k))
        while(l<r) {
            int m = l+(r-l)/2;
            if(abs(arr[m]-x)<=abs(arr[m+k]-x)) {
                r=m;
            } else {
                l=m+1;
            }
        }
        // O(k)
        return vector<int>(arr.begin()+l, arr.begin()+l+k);
    }
};
// T.C: O(log(n-k)+k)
// S.C: O(1)