class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int a = 0; a < n-3; a++){
            if(a > 0 and nums[a] == nums[a-1]) continue;
            
            for(int i = a+1; i < n-2; i++){
                if(i > a+1 and nums[i] == nums[i-1]){
                    continue;
                }

                int j = i+1;
                int k = n-1;
                while(j < k){
                    long long sum = 1LL * nums[a] + nums[i] + nums[j] + nums[k];
                    if(sum < target){
                        j++;
                    }else if(sum > target){
                        k--;
                    }else{
                        vector<int> temp = {nums[a], nums[i], nums[j], nums[k]};
                        ans.push_back(temp);
                        j++;
                        k--;
                        while(j < k and nums[j] == nums[j-1]) j++;
                        while(j < k and nums[k] == nums[k+1]) k--;
                    }
                }
            }
        }
        return ans;
    }
};