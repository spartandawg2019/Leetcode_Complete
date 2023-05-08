class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
int m = nums1.size();
int n = nums2.size();
if (m > n) {
return findMedianSortedArrays(nums2, nums1);
}
int partition = (m + n + 1) / 2;
int left = 0;
int right = m;
while (left < right) {
int mid1 = left + (right - left) / 2;
int mid2 = partition - mid1;
if (nums1[mid1] < nums2[mid2 - 1]) {
left = mid1 + 1;
} else {
right = mid1;
}
}
int mid1 = left;
int mid2 = partition - left;
int left_max = max(mid1 <= 0 ? INT_MIN : nums1[mid1 - 1], mid2 <= 0 ? INT_MIN : nums2[mid2 - 1]);
if ((m + n) % 2 == 1) {
return left_max;
}
int right_min = min(mid1 >= m ? INT_MAX : nums1[mid1], mid2 >= n ? INT_MAX : nums2[mid2]);
return (left_max + right_min) / 2.0;
}
};