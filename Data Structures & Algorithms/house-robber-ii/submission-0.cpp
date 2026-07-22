class Solution {
public:
     int f(int idx, int start, vector<int>& nums, vector<int>& dp){
        if(idx < start) return 0;
        if(dp[idx] != -1) return dp[idx];

        return dp[idx] = max((nums[idx] + f(idx-2, start, nums, dp)), (f(idx-1, start, nums, dp))); 
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        return max(f(n-1, 1, nums, dp1), f(n-2, 0, nums, dp2));
    }
};