class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            if(mpp.find(nums[i]-1) != mpp.end()){
                mpp[nums[i]] = mpp[nums[i]-1] + 1;
            }else{
                mpp[nums[i]] = 1;
            }
        }

        for(auto it : mpp){
            cnt = max(cnt, it.second);
        }

        return cnt;
    }
};
