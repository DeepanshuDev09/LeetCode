class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ansRow = -1;
        int st = 0, end = matrix.size() - 1;
        int n = matrix[0].size() - 1;

        while (st <= end){
            int mid = st + (end-st)/2;

            if (matrix[mid][0] <= target && matrix[mid][n] >= target){
                ansRow = mid;
                break;
            }
            else if (matrix[mid][0] > target){
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        if (ansRow == -1) return 0;
        st = 0; end = n;

        while (st <= end){
            int mid = st + (end-st)/2;

            if (matrix[ansRow][mid] > target){
                end = mid - 1;
            }
            else if (matrix[ansRow][mid] < target){
                st = mid + 1;
            }
            else {
                return 1;
            }
        }

        return 0;
    }
};