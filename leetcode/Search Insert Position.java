/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums contains distinct values sorted in ascending order.
-10^4 <= target <= 10^4*/

Solution:

class Solution {
    public int searchInsert(int[] nums, int target) {
        int n=nums.length;
        int m=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                return i;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<target&&nums[i+1]>target){
                m=i+1;
                break;
            }
        }
        if(nums[n-1]<target)
        {
            m=n;
        }
        return m;
    }
}