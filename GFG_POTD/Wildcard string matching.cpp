/*Given two strings wild and pattern. Determine if the given two strings can be matched given that, wild string may contain * and ? but string pattern will not. * and ? can be converted to another character according to the following rules:

* --> This character in string wild can be replaced by any sequence of characters, it can also be replaced by an empty string.
? --> This character in string wild can be replaced by any one character.
Example 1:

Input: 
wild = ge*ks
pattern = geeks
Output: Yes
Explanation: Replace the '*' in wild string 
with 'e' to obtain pattern "geeks".
Example 2:

Input: 
wild = ge?ks*
pattern = geeksforgeeks
Output: Yes
Explanation: Replace '?' and '*' in wild string with
'e' and 'forgeeks' respectively to obtain pattern 
"geeksforgeeks"
Your Task:
You don't need to read input or print anything. Your task is to complete the function match() which takes the string wild and pattern as input parameters and returns true if the string wild can be made equal to the string pattern, otherwise, returns false.

Expected Time Complexity: O(length of wild string * length of pattern string)
Expected Auxiliary Space: O(length of wild string * length of pattern string)

Constraints:
1 <= length of the two string <= 10^3 */

Solution:

// User function template for C++
class Solution{
    public:
    bool match(string wild, string pattern)
    {
int n = wild.size();
        int m = pattern.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        dp[n][m] = 1;
        
        for(int i = n - 1; i > -1; i--){
            for(int j = m - 1; j > -1; j--){
                if(wild[i] == '?')  
                    dp[i][j] = dp[i + 1][j + 1];
                else if(wild[i] == '*'){
                    if(i == n - 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i + 1][j] or dp[i][j + 1];
                }
                else{
                    if(wild[i] == pattern[j])
                        dp[i][j] = dp[i + 1][j + 1];
                    else
                        dp[i][j] = 0;
                }
            }
        }
        
        return dp[0][0];
    }
};