class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int b1 = -1, b2 = -1;
        int last1 = -1, last2 = -1;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            int x = fruits[right];

            if (x == b1) {
                last1 = right;
            }
            else if (x == b2) {
                last2 = right;
            }
            else if (b1 == -1) {
                b1 = x;
                last1 = right;
            }
            else if (b2 == -1) {
                b2 = x;
                last2 = right;
            }
            else {
                if (last1 < last2) {
                    left = last1 + 1;
                    b1 = x;
                    last1 = right;
                }
                else {
                    left = last2 + 1;
                    b2 = x;
                    last2 = right;
                }
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};