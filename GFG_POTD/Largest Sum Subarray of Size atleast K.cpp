/*Given an array a of length n and a number k, find the largest sum of the subarray containing at least k numbers. It is guaranteed that the size of array is at-least k.

Example 1:

Input : 
n = 4
a[] = {1, -2, 2, -3}
k = 2
Output : 
1
Explanation :
The sub-array of length at-least 2
that produces greatest sum is {1, -2, 2}
Example 2:
Input :
n = 6 
a[] = {1, 1, 1, 1, 1, 1}
k = 2
Output : 
6
Explanation :
The sub-array of length at-least 2
that produces greatest sum is {1, 1, 1, 1, 1, 1}
Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxSumWithK() which takes the array a[], its size n and an integer k as inputs and returns the value of the largest sum of the subarray containing at least k numbers.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 10^5
-10^5 <= a[i] <= 10^5
1 <= k <= n*/

Solution:

class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<long long> dp(n + 1, 0);
        
        for(int i = n - 1; i > -1; i--){
            dp[i] = a[i] + dp[i + 1];
            dp[i] = max(dp[i], 0LL);
        }
            
        long long ans = -1e18;
        
        long long cur_sum = 0;
        for(int i = 0; i < k; i++)
            cur_sum += a[i];
        
        for(int i = k; i < n; i++){
            long long sum = cur_sum + dp[i];
            ans = max(ans, sum);
            
            cur_sum += a[i];
            cur_sum -= a[i - k]; 
        }
        
        return max(ans, cur_sum);
    }
};