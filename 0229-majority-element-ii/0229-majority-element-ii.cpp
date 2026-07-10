class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int times = nums.size()/3;
        vector<int> result;
        int count1 = 0, count2 = 0;
        int elem1 = INT_MIN, elem2 = INT_MIN;
        
        for (int i = 0; i<nums.size(); i++){
            if (count1 == 0 && nums[i] != elem2){
                elem1 = nums[i];
                count1++;
            }
            else if (count2 == 0 && nums[i] != elem1){
                elem2 = nums[i];
                count2++;
            }
            else if (nums[i] == elem1){
                count1++;
            }
            else if (nums[i] == elem2){
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0; count2 = 0;

        for (int i: nums){
            if (i == elem1) count1++;
            if (i == elem2) count2++;
        }

        if (count1 > times) result.push_back(elem1);
        if (count2 > times) result.push_back(elem2);

        return result;
    }
};