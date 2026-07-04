class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        int result = 0;
        int elem = 0;

        for (int i = 0; i<nums.size(); i++){
            if (mpp.find(nums[i]) != mpp.end()){
                mpp[nums[i]]++;
            }
            else {
                mpp[nums[i]] = 1;
            }
        }

        for (auto it : mpp){
            if (it.second > result){
                result = it.second;
                elem = it.first;
            }
        }

        return elem;
    }
};