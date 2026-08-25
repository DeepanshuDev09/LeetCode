class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> multiples(nums.size(), -1);

        for (int i = 0; i<nums.size(); i++){
            if (nums[i] % k == 0){
                int curr = nums[i]/k - 1;
                if (curr >= 0 && curr < multiples.size()) {
                    multiples[curr] = 1;
                }
            }
        }

        for (int i = 0; i<multiples.size(); i++){
            if (multiples[i] == -1) return k*(i+1);
        }

        return k*(nums.size()+1);
    }
};