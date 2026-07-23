class Solution {
public:
    // unordered_map<int, string>mpp;

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
        int m = wordDict.size();

        // for(int i = 0; i < m; i++){
        //     mpp[i] = wordDict[i];
        // }

        vector<int> dp(n+1, -1);
        // dp[n] = true;

        return f(0, s, n, wordDict, dp);
    }
};
