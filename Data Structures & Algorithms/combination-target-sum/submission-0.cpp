class Solution {
public:
    void f(int idx, vector<int>& nums, vector<int>& comb, vector<vector<int>>& ans, int target){
        if(idx == nums.size() or target < 0){
            return;
        }

        if(target == 0){
            ans.push_back(comb);
            return;
        }

        comb.push_back(nums[idx]);
        f(idx, nums, comb, ans, target - nums[idx]);
        comb.pop_back();
        f(idx + 1, nums, comb, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        f(0, nums, comb, ans, target);
        return ans;
    }
};
