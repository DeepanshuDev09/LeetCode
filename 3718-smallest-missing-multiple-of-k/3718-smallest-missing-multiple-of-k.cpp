class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int, int> multiples;

        for (int i = 1; i<=nums.size(); i++){
            multiples[k*i]++;
        }

        for (int i = 0; i<nums.size(); i++){
            if (nums[i] % k == 0){
                multiples[nums[i]] = 0;
            }
        }

        for (auto it: multiples){
            if (it.second == 1) return it.first;
        }

        return k*(nums.size()+1);
    }
};