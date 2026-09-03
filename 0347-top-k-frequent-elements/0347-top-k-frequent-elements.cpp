class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> freq;

        for (int i: nums) freq[i]++;

        while (k > 0){
            int maxSize = INT_MIN;
            int curr;
            for (auto it: freq){
                if (it.second > maxSize){
                    curr = it.first;
                    maxSize = it.second;
                }
            }

            ans.push_back(curr);
            freq.erase(curr); k--;
        }

        return ans;
    }
};