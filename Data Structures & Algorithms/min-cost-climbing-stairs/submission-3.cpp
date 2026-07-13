class Solution {
public:
    int f(int idx, vector<int>& cost, vector<int>& dp){
        if(idx < 2) return 0;
        if(dp[idx] != -1) return dp[idx];

        return dp[idx] = min(cost[idx-1] + f(idx-1, cost, dp), cost[idx-2] + f(idx-2, cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n+1, -1);
        // return f(n, cost, dp);
        vector<int> dp(n+1, 0);

        for(int i = 0; i <= n; i++){
            if(i < 2) dp[i] = 0;
            else{
                dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]); 
            }
        }

        return dp[n];
    }
};
