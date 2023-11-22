/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6*/

Solution:

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        vector<int> nums;
        while(i<m&&j<n) 
        {
            if(nums1[i]<=nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
            } 
            else 
            {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m)
        {
            nums.push_back(nums1[i]);
            i++;
        }
        while(j<n)
        {
            nums.push_back(nums2[j]);
            j++;
        }
        int arr=nums.size();
        if(arr%2==1) 
        {
            return static_cast<double>(nums[arr/2]);
        }
        else 
        {
            int m1=nums[arr/2-1];
            int m2=nums[arr/2];
            return (static_cast<double>(m1)+static_cast<double>(m2))/2.0;
        }
    }
};
