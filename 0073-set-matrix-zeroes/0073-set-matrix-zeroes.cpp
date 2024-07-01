class Solution {
public:

    bool func(int val,vector<vector<int>>& matrix, int n, int m){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == val){
                    return false;
                }
            }
        }
        return true;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int val = 1, n=matrix.size(), m= matrix[0].size();
        while(!func(val,matrix,n,m)) {
            val++;
        }

        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][j] = val;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==val){
                    matrix[i][j]=0;
                    for(int ix = 0; ix <n; ix++){
                        if(matrix[ix][j] != val) matrix[ix][j] = 0;
                    }
                    for(int jx = 0; jx<m; jx++){
                        if(matrix[i][jx]!= val) matrix[i][jx] = 0;
                    }
                }
            }
        }
    }
};