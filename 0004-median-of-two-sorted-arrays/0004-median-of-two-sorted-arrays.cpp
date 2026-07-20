class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        int i = 0;
        int j = 0;
        vector<int> nums;

        while (i < nums1.size() && j < nums2.size()){
            if ( nums1[i] < nums2[j] ){
                nums.push_back(nums1[i]);
                i++;
            }
            else {
                nums.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) { nums.push_back(nums1[i]); i++; }
        while (j < nums2.size()) { nums.push_back(nums2[j]); j++; }

        if ((nums.size())%2 != 0){
           int mid = (nums.size() - 1)/2;
           ans = nums[mid];
        }
        else {
            int mid = (nums.size() - 1)/2;
            ans = (double(nums[mid]) + double(nums[mid+1]))/2;
        }
        return ans;
    }
};