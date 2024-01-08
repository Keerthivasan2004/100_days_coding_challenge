/*Given a string s, check if it is possible to convert it into a string that is the repetition of a substring of length k. Conversion has to be done by following the steps mentioned below only once:

Select two indices i and j (zero-based indexing, i could be equal to j), such that i and j are divisible by k.
Select substrings of length k starting from indices i and j.
Replace substring starting at index i with substring starting at index j within the string
Note: You have to convert the string using the operation only once.

Example 1:

Input:
N = 4
K = 2
S = "bdac"
Output: 1
Explanation: We can replace either
"bd" with "ac" or "ac" with "bd"
Example 2:

Input: 
N = 5
K = 2
S = "abcde"
Output: 0
Explanation: Since n % k != 0, it's not 
possible to convert s into a string which
is a concatanation of a substring with 
length k.
Your Task:
You don't need to read input or print anything. Your task is to complete the function kSubstrConcat() which takes a string s, its length n and an integer k as inputs and return 1 if convertion of the given string is possible, else 0.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
2 <= k < n <= 10^5

Solution:

//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    if(n % k)
	        return 0;
	        
	    map<vector<int>, int> substr;
	    
	    vector<int> f(26, 0);
	    
	    for(int i = 0; i < n; i += k){
	        for(int j = i - k; j < i and j > -1; j++)
	            --f[s[j] - 'a'];
	        for(int j = i; j < i + k; j++)
	            ++f[s[j] - 'a'];
	        
	        substr[f]++;
	        
	        if(substr.size() > 2)
	            return 0;
	    }
	    
	    int freq = (*substr.begin()).second;
	    
	    return (freq == 1 or freq >= n / k - 1);
	}
};