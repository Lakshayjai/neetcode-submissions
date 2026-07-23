class Solution {
public:
    int f(int prevIdx, int idx, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(idx == n) return 0;

        // while(nums[idx] <= prev){
        //     idx++;
        // }

        if(dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];

        int not_take = 0 + f(prevIdx, idx + 1, n, nums, dp);
        int take = 0;

        if(prevIdx == -1 or nums[idx] > nums[prevIdx]){
            take = 1 + f(idx, idx + 1, n, nums, dp);
        }

        return dp[idx][prevIdx + 1] = max(take, not_take); 
    }

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int prevIdx = -1;

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return f(prevIdx, 0, n, nums, dp);
    }
};
