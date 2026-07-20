class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        for (int i: nums2){
            nums1.push_back(i);
        }
        sort(nums1.begin(), nums1.end());
        if ((nums1.size())%2 != 0){
           int mid = (nums1.size() - 1)/2;
           ans = nums1[mid];
        }
        else {
            int mid = (nums1.size() - 1)/2;
            ans = (double(nums1[mid]) + double(nums1[mid+1]))/2;
        }
        return ans;
    }
};