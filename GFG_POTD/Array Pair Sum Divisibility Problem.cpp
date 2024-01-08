/*Given an array of integers nums and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

Example 1 :

Input : 
nums = [9, 5, 7, 3]
k = 6
Output: 
True
Explanation: 
{(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.
Example 2:

Input : 
nums = [4, 4, 4]
k = 4
Output: 
False
Explanation: 
You can make 1 pair at max, leaving a single 4 unpaired.
Your Task:
You don't need to read or print anything. Your task is to complete the function canPair() which takes array nums and k as input parameter and returns true if array can be divided into pairs such that sum of every pair is divisible by k otherwise returns false.

Expected Time Complexity: O(n)
Expected Space Complexity : O(n)

Constraints:
1 <= length( nums ) <= 10^5
1 <= numsi <= 10^5
1 <= k <= 10^5*/

Solution:

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        map<int,int> f;
        
        for(int i = 0; i < nums.size(); i++){
            int cur = nums[i] % k;
            int need = (k - cur) % k;
            
            if(f.count(need)){
                --f[need];
                
                if(f[need] == 0)
                    f.erase(need);
            }
            else{
                ++f[cur];
            }
        }
        
        return f.size() == 0;
    }
};