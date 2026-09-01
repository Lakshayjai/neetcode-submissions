class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for(int i = 0; i < strs.size(); i++){
            string srtS = strs[i];
            sort(srtS.begin(), srtS.end());
            mpp[srtS].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto str : mpp){
            ans.push_back(str.second);
        }

        return ans;
    }
};


