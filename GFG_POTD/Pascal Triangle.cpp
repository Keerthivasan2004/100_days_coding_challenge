/*Given a positive integer N, return the Nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.
The elements can be large so return it modulo 10^9 + 7.


Example 1:

Input:
N = 4
Output: 
1 3 3 1
Explanation: 
4th row of pascal's triangle is 1 3 3 1.
Example 2:

Input:
N = 5
Output: 
1 4 6 4 1
Explanation: 
5th row of pascal's triangle is 1 4 6 4 1.
Your Task:
Complete the function nthRowOfPascalTriangle() which takes n, as input parameters and returns an array representing the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ N ≤ 10^3*/

Solution:

class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        const long long mod=1e9+7;
        vector<vector<long long>> ans(n,vector<long long>(n,1));
        for(int i=2;i<n;i++)
        {
            for(int j=1;j<i;j++)
            {
                ans[i][j]=(ans[i-1][j-1]+ans[i-1][j])%mod;
            }
        }
        return ans.back();
    }
};
