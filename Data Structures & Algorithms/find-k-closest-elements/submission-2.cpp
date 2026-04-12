class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int i=0;
        for(int j=0;j<n;j++) {
            if(j-i+1>k) {
                if((abs(arr[i]-x)<=abs(arr[j]-x)) && (arr[i]<arr[j])) {
                    vector<int>ans;
                    for(int l=i;l<j;l++) ans.push_back(arr[l]);
                    return ans;
                } else {
                    i++;
                }
            }
        }
        vector<int>ans;
        for(int l=i;l<n;l++) ans.push_back(arr[l]);
        return ans;
    }
};