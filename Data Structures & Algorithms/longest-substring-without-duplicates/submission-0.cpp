class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int len = 0;

        unordered_map<char, int> mpp;
        
        for(int j = 0; j < s.length(); j++){
            mpp[s[j]]++;

            while(mpp[s[j]] > 1){
                mpp[s[i]]--;
                i++;
            }

            int dis = j - i + 1;
            len = max(len, dis);
        }

        return len;
    }
};
