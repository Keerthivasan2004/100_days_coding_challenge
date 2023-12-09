/*Given a number n, the task is to find out whether this number is a Smith number or not. A Smith number is a composite number whose sum of digits is equal to the sum of digits of its prime factors.

Example 1:

Input:
n = 4
Output:
1
Explanation:
The sum of the digits of 4 is 4, and the sum of the digits of its prime factors is 2 + 2 = 4.
Example 2:

Input:
n = 378
Output:
1
Explanation:
378 = 21*33*71 is a Smith number since 3+7+8 = 2*1+3*3+7*1.*/

Solution:


class Solution {
  public:
        int digitSum(int n){
        int ans = 0;
        
        while(n){
            ans += n % 10;
            n /= 10;
        }
        
        return ans;
    }
    
    int smithNum(int n) {
        vector<int> sieve(n + 1, 1e9);
        
        for(int i = 2; i < n + 1; i++){
            if(sieve[i] == 1e9){
                sieve[i] = i;
                for(int j = i + i; j < n + 1; j += i)
                    sieve[j] = min(sieve[j], i);
            }
        }
        
        if(sieve[n] == n)
            return 0;
        
        int suma, sumb;
        suma = sumb = 0;
        
        sumb = digitSum(n);
        
        while(n > 1){
            suma += digitSum(sieve[n]);
            n /= sieve[n];
        }
        
        return suma == sumb;
    }
};