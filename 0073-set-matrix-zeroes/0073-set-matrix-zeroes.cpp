class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        vector<int> zeroRow;
        vector<int> zeroCol;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                if (nums[i][j] == 0) {
                    zeroRow.push_back(i);
                    zeroCol.push_back(j);
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                if (find(zeroRow.begin(), zeroRow.end(), i) != zeroRow.end()) {
                    nums[i][j] = 0;
                }
                else if (find(zeroCol.begin(), zeroCol.end(), j) != zeroCol.end()) {
                    nums[i][j] = 0;
                }
            }
        }
    }
};