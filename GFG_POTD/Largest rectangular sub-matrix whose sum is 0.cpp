/*Given a matrix mat[][] of size N x M. The task is to find the largest rectangular sub-matrix by area whose sum is 0.

If there are multiple solutions return the rectangle which starts from minimum column index. If you still have multiple solutions return the one having the least width (number of columns included in the sub-matrix) starting from the minimum row index. If no such matrix is present return a zero (0) size matrix.

Example 1:

Input: N = 3, M = 3
mat[][] =  1, 2, 3
          -3,-2,-1
           1, 7, 5

Output:  1, 2, 3
        -3,-2,-1

Explanation: This is the largest sub-matrix,
whose sum is 0.
Example 2:

Input: N = 4, M = 4
mat[][] = 9, 7, 16, 5
          1,-6,-7, 3
          1, 8, 7, 9
          7, -2, 0, 10

 Output: -6,-7
          8, 7
         -2, 0 
Your Task:
You don't need to read input or print anything. You just have to complete the function sumZeroMatrix() which takes a 2D matrix mat[][], its dimensions N and M as inputs and returns a largest sub-matrix, whose sum is 0.

Expected Time Complexity: O(N*M*M).
Expected Auxiliary Space: O(N*M).


Constraints:
1 <= N, M <= 100
-1000 <= mat[][] <= 1000*/

Solution:

//User function Template for C++

class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
      int n = a.size();
        int m = a[0].size();
        
        vector<vector<int>> rowPrefix(n + 1, vector<int> (m + 1, 0));
        
        for(int i = 1; i < n + 1; i++)
        {
          for(int j = 1; j < m + 1; j++)
            rowPrefix[i][j] += rowPrefix[i][j - 1] + a[i - 1][j - 1];
        }
        
        int best = 0;
        int sx, sy, ex, ey;
        for(int i = 1; i < m + 1; i++)
        {
          for(int j = i; j < m + 1; j++)
          {
              map<int,int> pre;
              pre[0] = 0;
              
              int csum = 0;
              for(int k = 1; k < n + 1; k++)
              {
                  csum += rowPrefix[k][j] - rowPrefix[k][i - 1];
                  
                  if(pre.count(csum))
                  {
                      int area = (j - i + 1) * (k - pre[csum]);
                      
                      if(area > best){
                          best = area;
                          
                          sx = pre[csum] + 1;
                          sy = i;
                          
                          ex = k;
                          ey = j;
                      }
                  }
                  else
                      pre[csum] = k;
              }
          }
        }
      
        vector<vector<int>> ans;
      
        if(best == 0)
            return ans;
        
        for(int i = sx; i < ex + 1; i++)
        {
            vector<int> curRow;
            for(int j = sy; j < ey + 1; j++)
                curRow.push_back(a[i - 1][j - 1]);
            
            ans.emplace_back(curRow);
        }
        
        return ans;
  }
};