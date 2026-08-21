class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        if (nums.size() < 3) return nums;
        vector<int> arr1;
        vector<int> arr2;

        for (int i = 0; i<nums.size(); i++){
            if (arr1.empty()){
                arr1.push_back(nums[i]);
            }
            else if (arr2.empty()){
                arr2.push_back(nums[i]);
            }
            else if (arr1.back() > arr2.back()){
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }

        for (int i: arr2) arr1.push_back(i);

        return arr1;
    }
};