class Solution {
public:
    void f(int idx, vector<int>& nums, vector<int>& comb, vector<vector<int>>& ans, int target){

        if(target == 0){
            ans.push_back(comb);
            return;
        }
        
        if(idx == nums.size() or target < 0){
            return;
        }


        for(int i = idx; i < nums.size(); i++){
            if(i > idx and nums[i] == nums[i-1]) continue;

            if(nums[i] > target){
                break;
            }
            
            comb.push_back(nums[i]);
        
            f(i + 1, nums, comb, ans, target - nums[i]);
            
            comb.pop_back();

        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> comb;

        f(0, nums, comb, ans, target);

        return ans;
    }
};
