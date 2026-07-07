class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        vector<int> zeroCol;

        for (int i = 0; i < nums.size(); i++) {
            int found = 0;
            for (int j = 0; j < nums[0].size(); j++) {
                if (nums[i][j] == 0) {
                    found = 1;
                    zeroCol.push_back(j);
                }
            }
            if (found == 1){
                for (int j = 0; j< nums[0].size(); j++){
                    nums[i][j] = 0;
                }
            }
        }

        for (int j = 0; j<nums[0].size(); j++){
            if (find(zeroCol.begin(), zeroCol.end(), j) != zeroCol.end()){
                for (int i = 0; i<nums.size(); i++){
                    nums[i][j] = 0;
                }
            }
        }
    }
};