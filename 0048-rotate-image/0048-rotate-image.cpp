class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j>i) swap(matrix[j][i],matrix[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            int j=0,k=n-1;
            while(j<=k){
                swap(matrix[i][j],matrix[i][k]);
                j++;
                k--;
            }
        }
    }
};