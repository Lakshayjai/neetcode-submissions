class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0];
        int ans = nums[0];

        // if(nums.size() == 1) return nums[0];

        for(int i = 1; i < nums.size(); i++){
            int curr = max(nums[i], nums[i] + prev);
            ans = max(ans, curr);
            prev = curr;
        }
        return ans;
    }
};
