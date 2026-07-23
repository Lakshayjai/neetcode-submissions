class Solution {
public:
    int f(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){
        
        if(amount == 0) return 0;

        if(dp[idx][amount] != -1) return dp[idx][amount];

        if(idx == 0){
            if(amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        int notTake = f(idx-1, coins, amount, dp);
        int take = 1e9;

        if(coins[idx] <= amount){
            take = 1 + f(idx, coins, amount - coins[idx], dp);
        }

        return dp[idx][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        // int ans = f(n-1, coins, amount, dp);
        // return (ans >= 1e9) ? -1 : ans;

        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        for(int i = 0; i < n; i++){
            for(int amt = 0; amt <= amount; amt++){

                if(i == 0){
                    if(amt % coins[0] == 0){
                        dp[0][amt] = amt / coins[0];
                    }else{
                        dp[0][amt] = 1e9;                                                                                                                                                                                                                                                                                                                                                                                       
                    }
                }else{
                    int notTake = dp[i-1][amt];
                    int take = 1e9;

                    if(coins[i] <= amt){
                        take = 1 + dp[i][amt - coins[i]];
                    }

                    dp[i][amt] = min(take, notTake);
                }
            }
        }
        
        int res = dp[n-1][amount];
        return (res >= 1e9) ? -1 : res;
    }
};
