class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int times = nums.size()/3;
        vector<int> result;
        unordered_map<int, int> freq;

        for(int i: nums){
            freq[i]++;
        }

        for(auto i: freq){
            if (i.second > times) result.push_back(i.first);
        }

        return result;
    }
};