class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size() - 1;
        k = k % nums.size();
        vector<int> rotate;

        for (int i = nums.size()-1; i>=0; i--){
            if (k > 0){
                rotate.push_back(nums[i]);
                k--;
            }
            else {
                swap(nums[i], nums[n]);
                n--;
            }
        }

        int size = rotate.size()-1;
        for (int i = 0; i<=n; i++){
            nums[i] = rotate[size];
            size--;
        }
    }
};