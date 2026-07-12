class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for (int i = 1; i<intervals.size(); i++){
            int curr = result.back().back();

            if (curr >= intervals[i][0]){
                if (curr < intervals[i][1]){
                    result.back().back() = intervals[i][1];
                }
            }
            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};