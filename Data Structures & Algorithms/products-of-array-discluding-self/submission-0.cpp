class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            int ans = 1;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                else{
                    ans *= nums[j];
                }
            }
            temp[i] = ans;
        }

        return temp;
    }
};
