class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        stack<int> stRight;
        stack<int> stLeft;
        vector<int> ans(n, 1);

        for (int i = n - 1; i >= 0; i--) {

            while (!stRight.empty() && heights[stRight.top()] >= heights[i]) stRight.pop();

            if (!stRight.empty()) {
                ans[i] += stRight.top() - i - 1;
            } else {
                ans[i] += n - i - 1;
            }

            stRight.push(i);
        }

        for (int i = 0; i < n; i++) {

            while (!stLeft.empty() && heights[stLeft.top()] >= heights[i]) {
                stLeft.pop();
            }

            if (!stLeft.empty()) {
                ans[i] += i - stLeft.top() - 1;
            } else {
                ans[i] += i;
            }

            stLeft.push(i);
        }

        for (int i = 0; i<n; i++){
            int currArea = heights[i] * ans[i];
            maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
    }
};