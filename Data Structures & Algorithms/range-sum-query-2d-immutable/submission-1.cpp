class NumMatrix {
    vector<vector<int>> prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        prefixSum.resize(n, vector<int>(m,0));
        for(int i=0;i<n;i++) {
            prefixSum[i][0]=matrix[i][0];
            for(int j=1;j<m;j++) {
                prefixSum[i][j]=prefixSum[i][j-1]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int r=row1;r<=row2;r++){
            sum+=prefixSum[r][col2]-prefixSum[r][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */