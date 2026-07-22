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
