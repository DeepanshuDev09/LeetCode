class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        int ans = 0;

        for (int i = 0; i<m; i++){
            
            for (int j = 0; j<n; j++){

                if (matrix[i][j] == '0') continue;

                int row = j, col = i;
                int rowCount = 0, colCount = 0;

                while (row < n && matrix[i][row] == '1'){
                    row++; rowCount++;
                    ans = max(ans, rowCount);
                }

                int width = rowCount;

                while (col < m && matrix[col][j] == '1'){ 

                    row = j+1; rowCount = 1;
                    while (row < n && matrix[col][row] == '1'){
                        row++; rowCount++;
                    }

                    col++; colCount++;
                    width = min(rowCount, width);
                    ans = max(ans, (width * colCount));  
                }
            }
        }

        return ans;
    }
};