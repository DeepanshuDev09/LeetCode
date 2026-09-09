class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        vector<bool> indexGo(n, false);

        for (int i = n-1; i>=0; i--){
            if (i == n - 1){
                indexGo[i] = true;
                continue;
            }

            int temp = i + nums[i];
            while (temp > i){
                if (temp < n && indexGo[temp] == true){
                    indexGo[i] = true;
                    break;
                }
                temp--;
            }
        }

        return indexGo[0];
    }
};