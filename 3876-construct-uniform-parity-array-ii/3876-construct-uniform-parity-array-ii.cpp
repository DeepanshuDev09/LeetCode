class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestEven = INT_MAX;
        int smallestOdd = INT_MAX;

        for (int i: nums1){
            if (i % 2 == 0){
                smallestEven = min(smallestEven, i);
            }
            else {
                smallestOdd = min(smallestOdd, i);
            }
        }

        if (smallestEven == INT_MAX || smallestOdd == INT_MAX) return true;

        bool checkEven = true, checkOdd = true;

        for (int i: nums1){
            if (i % 2 == 0){
                if (i - smallestEven >= 1 || i - smallestOdd >= 1) continue;
                checkEven = false;
            }
            else {
                if (i - smallestOdd >= 1 && i - smallestEven >= 1) continue;
                checkOdd = false;
            }
        }

        if (checkEven || checkOdd) return true;

        return false;
    }
};