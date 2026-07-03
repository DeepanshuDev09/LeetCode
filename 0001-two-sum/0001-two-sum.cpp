class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());

        int i = 0, j = copy.size() - 1;
        int a, b;

        while (i < j) {
            int sum = copy[i] + copy[j];

            if (sum < target)
                i++;
            else if (sum > target)
                j--;
            else {
                a = copy[i];
                b = copy[j];
                break;
            }
        }

        vector<int> result;

        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] == a) {
                result.push_back(k);
                break;
            }
        }

        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] == b && k != result[0]) {
                result.push_back(k);
                break;
            }
        }

        return result;
    }
};