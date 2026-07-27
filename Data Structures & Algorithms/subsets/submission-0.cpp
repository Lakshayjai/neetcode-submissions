class Solution {
public:
    void f(vector<int>& nums, int idx, vector<int>& temp, vector<vector<int>>& ans){

        if(idx >= nums.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[idx]);
        f(nums, idx + 1, temp, ans);
        temp.pop_back();
        f(nums, idx + 1, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;
        f(nums, 0, temp, ans);
        return ans; 
    }
};
