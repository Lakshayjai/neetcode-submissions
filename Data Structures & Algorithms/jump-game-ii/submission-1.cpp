class Solution {
public:
    int f(int idx, int n, vector<int>& nums, vector<int>& dp){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int ans = INT_MAX;

        for(int i = idx + 1; i <= idx + nums[idx]; i++){
            int jumps = f(i, n, nums, dp);

            if(jumps != INT_MAX){
                ans = min(ans, 1 + jumps);
            }
        }
        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return f(0, n-1, nums, dp);
    }
};
