class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int foundOdd = -1;
        int foundEven = -1;

        for (int i = 0; i<nums1.size(); i++){
            if (nums1[i] % 2 != 0){
                foundOdd = 1;
            }
            else {
                foundEven = 1;
            }
        }

        if (foundOdd == 1 && foundEven == -1) return true;
        if (foundEven == 1 && foundOdd == -1) return true;
        if (foundEven = 1 && foundOdd == 1) return true;

        return false;
    }
};