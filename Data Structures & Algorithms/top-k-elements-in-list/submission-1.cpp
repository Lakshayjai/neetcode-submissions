class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        unordered_map<int, int> mpp;

        for(auto it : nums){
            mpp[it]++;
        }

        vector<pair<int, int>> temp;
        for(auto it : mpp){
            temp.push_back({it.second, it.first});
        }

        sort(temp.rbegin(), temp.rend());

        for(int i = 0; i < k; i++){
            ans.push_back(temp[i].second);
        }

        return ans;
    }
};
