class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int l=0, h=rows*cols-1;
        while(l<h) {
            int m = l+(h-l)/2;
            // if (r,c) -> m, then m=r*cols+c;
            int r=m/cols, c=m%cols;
            if(matrix[r][c]>=target) h=m;
            else l=m+1;
        }
        int r = l/cols, c=l%cols;
        if(matrix[r][c]==target) return true;
        return false;
    }
};
