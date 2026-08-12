class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        int maxArea = 0;
        vector<int> arr(n, 0);

        for (int i = 0; i<m; i++){

            for (int j = 0; j<n; j++){
                if (matrix[i][j] == '0'){
                    arr[j] = 0;
                }
                else {
                    arr[j] += 1;
                }
            }

            stack<int> stLeft;
            vector<int> ans(n, 1);

            for (int j = 0; j<n; j++) {

                while (!stLeft.empty() && arr[stLeft.top()] >= arr[j]) stLeft.pop();

                if (!stLeft.empty()) {
                    ans[j] += j - stLeft.top() - 1;
                } else {
                    ans[j] += j;
                }

                stLeft.push(j);
            }

            stack<int> stRight;

            for (int j = n - 1; j >= 0; j--) {

                while (!stRight.empty() &&
                       arr[stRight.top()] >= arr[j]) {
                    stRight.pop();
                }

                if (!stRight.empty())
                    ans[j] += stRight.top() - j - 1;
                else
                    ans[j] += n - j - 1;

                stRight.push(j);
            }

            for (int j = 0; j<n; j++){
                int currArea = arr[j] * ans[j];
                maxArea = max(maxArea, currArea);
            }
        }

        return maxArea;
    }
};