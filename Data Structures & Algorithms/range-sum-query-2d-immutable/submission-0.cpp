class NumMatrix {
    vector<vector<int>> mat;
    vector<vector<int>> prefixSum;
    void calculatePrefixSum() {
        int n=mat.size(),m=mat[0].size();
        prefixSum.resize(n, vector<int>(m,0));
        for(int i=0;i<n;i++) {
            prefixSum[i][0]=mat[i][0];
            for(int j=1;j<m;j++) {
                prefixSum[i][j]=prefixSum[i][j-1]+mat[i][j];
            }
        }
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->mat = matrix;
        this->calculatePrefixSum();
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int r=row1;r<=row2;r++){
            sum+=prefixSum[r][col2]-prefixSum[r][col1]+mat[r][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */