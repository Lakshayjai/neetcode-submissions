class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        int ans = INT_MIN;
        int res;

        for(auto m : mp){
            if(m.second > ans){
                ans = m.second;
                res = m.first;
            }
        }

        return res;
    }
};