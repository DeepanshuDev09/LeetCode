class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i<numRows; i++){
            
            vector<int> currRow;
            for (int j = 0; j<=i; j++){
                if (j == 0 || j == i){
                    currRow.push_back(1);
                    continue;
                }
                
                int currSum = ans[i-1][j] + ans[i-1][j-1];
                currRow.push_back(currSum);
            }

            ans.push_back(currRow);
        }

        return ans;
    }
};