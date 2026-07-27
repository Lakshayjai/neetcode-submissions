class Solution {
public:
    bool f(vector<int>& nums, int idx, int target){
        // base case
        if(target == 0) return true;
        if(idx >= nums.size()) return false;

        if(f(nums, idx + 1, target - nums[idx]) == true){
            return true;
        }

        if(f(nums, idx + 1, target) == true){
            return true;
        } 

        return false;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums) sum += it;

        if(sum % 2 != 0) return false;

        return f(nums, 0, sum/2);
    }
};
