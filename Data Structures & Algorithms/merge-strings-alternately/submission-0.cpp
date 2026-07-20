class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int i = 0;
        int j = 0;

        string ans;

        while(i < n and j < m){
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;
            j++;
        }

        if(i < n){
            ans.append(word1.substr(i, n-i));
        }

        if(j < m){
            ans.append(word2.substr(j, m-j));
        }

        return ans;
    }
};