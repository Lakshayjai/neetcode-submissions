class Solution {
public:
    int f(int n, vector<int>& dp){
        if(dp[n] != -1) return dp[n];

        if(n == 0) return 0;
        if(n == 1 or n == 2) return 1;
        return dp[n] = f(n-1, dp) + f(n-2, dp) + f(n-3, dp);
    }

    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};