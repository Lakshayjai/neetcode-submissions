class Solution {
public:
    int ans = 0;

    void backtrack(int idx, int currXor, vector<int>& nums) {
        if (idx == nums.size()) {
            ans += currXor;
            return;
        }

        backtrack(idx + 1, currXor, nums);

        backtrack(idx + 1, currXor ^ nums[idx], nums);
    }

    int subsetXORSum(vector<int>& nums) {
        backtrack(0, 0, nums);
        return ans;
    }
};