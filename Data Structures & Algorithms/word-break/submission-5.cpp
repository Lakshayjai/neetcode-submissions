class Solution {
public:

    bool f(int idx, string s, int n, vector<string>& wordDict, vector<int>& dp){
        if(idx == n) return true;

        if(dp[idx] != -1) return dp[idx];

        for(string w : wordDict){
            if(idx + w.length() <= n and s.substr(idx, w.length()) == w){
                if(f(idx + w.length(), s, n, wordDict, dp)) return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        // vector<int> dp(n+1, -1);
        // return f(0, s, n, wordDict, dp);

        vector<bool> dp(n+1, false);
        dp[n] = true;

        for(int i = n-1; i >= 0; i--){
            for(string w : wordDict){
                if(i + w.length() <= n and s.substr(i, w.length()) == w 
                and dp[i + w.length()]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
