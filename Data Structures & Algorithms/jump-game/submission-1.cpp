class Solution {
public:
    bool f(int idx, int n, vector<int>& nums, vector<int>& dp){
        if(idx >= n) return true;
        if(dp[idx] != -1) return dp[idx];

        for(int i = idx+1; i <= idx + nums[idx]; i++){
            if(f(i, n, nums, dp)) return true;
        }
        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return f(0, n-1, nums, dp);
    }
};
