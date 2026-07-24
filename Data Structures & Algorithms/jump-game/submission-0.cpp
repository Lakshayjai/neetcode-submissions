class Solution {
public:
    bool f(int idx, int n, vector<int>& nums){
        if(idx >= n) return true;

        for(int i = idx+1; i <= idx + nums[idx]; i++){
            if(f(i, n, nums)) return true;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();

        return f(0, n-1, nums);
    }
};
