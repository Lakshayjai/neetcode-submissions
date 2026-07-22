/*
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int resLen = 0;
        int resIdx = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++){
            
            // ODD LENGTH
            int l = i;
            int r = i;
            while(l >= 0 and r < n and s[l] == s[r]){
                if(r - l + 1 > resLen){
                    resIdx = l;
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }

            // EVEN LENGTH
            l = i;
            r = i + 1;
            while(l >= 0 and r < n and s[l] == s[r]){
                if(r - l + 1 > resLen){
                    resIdx = l;
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }

        }

        return s.substr(resIdx, resLen);
    }
};

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int resLen = 0;
        int resIdx = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] and (j - i <= 2 or dp[i+1][j-1])){
                    
                    dp[i][j] = true;

                    if(resLen < (j - i + 1)){
                        resIdx = i;
                        resLen = j - i + 1;
                    }
                }
            }
        }

        return s.substr(resIdx, resLen);
    }
};

